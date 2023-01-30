#include <HAL/LED/LED.h>
#include <HAL/IR/IR.h>
#include <HAL/FLAME/FLAME.h>
#include <HAL/LCD/LCD.h>
#include <HAL/KEY_PAD/KEY_PAD.h>
#include <HAL/BUZZER/BUZZER.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define CLOSED_DOOR 0
#define OPENED_DOOR 1

#define FALSE 0
#define TRUE  1

#define  STRING_MAX_SIZE 5

u8 FLAME_READ_ALL(){
    if(FLAME_READ(FLAME_1) == FIRE_DETECTED){
        return FIRE_DETECTED;
    }
    if(FLAME_READ(FLAME_2) == FIRE_DETECTED){
        return FIRE_DETECTED;
    }
    if(FLAME_READ(FLAME_3) == FIRE_DETECTED){
        return FIRE_DETECTED;
    }
    return NO_FIRE_DETECTED;
}

u8 IR_READ_ALL(){
    u8 value=0;
    if(IR_READ(IR_1) == OBJECT_DETECTED){
        value+=1;
    }
    if(IR_READ(IR_2) == OBJECT_DETECTED){
        value+=2;
    }
    if(IR_READ(IR_3) == OBJECT_DETECTED){
        value+=4;
    }
    return value;
}

u8 CompareStrings(u8* first, u8* second){
    for(u8 i=0;i<STRING_MAX_SIZE;i++){
        if(first[i] != second[i]){
            return FALSE;
        }
    }
    return TRUE;
}

void AssignStrings(u8* first, u8* second){
    for(u8 i=0;i<STRING_MAX_SIZE;i++){
        first[i] = second[i];
    }
}

int main(){
    u8 IR1_Action = NotPressed;
    u8 IR2_Action = NotPressed;
    u8 IR3_Action = NotPressed;
    u8 DoorState = CLOSED_DOOR;
    u8 reset = FALSE;
    u8 ResetCounter=0;
    u8 PasswordCounter = 0;
    u8 Password[STRING_MAX_SIZE] = "1234";
    u8 NewPassword[STRING_MAX_SIZE];
    u8 EnteredPassword[STRING_MAX_SIZE];
    LCD_INIT();
    KEY_PAD_INIT();
    IR_INIT(IR_1);
    IR_INIT(IR_2);
    IR_INIT(IR_3);
    FLAME_INIT(FLAME_1);
    FLAME_INIT(FLAME_2);
    FLAME_INIT(FLAME_3);
    LED_INIT(LED_0);
    LED_INIT(LED_1);
    LED_INIT(LED_2);
    BUZZER_INIT();
    BUZZER_OFF();
    while(1){
        u8 data = IR_READ_ALL();
        switch(data){
            case 1:
                if(IR1_Action == NotPressed){
                    LED_TOG(LED_0);
                    IR1_Action = Pressed;
                }
                IR2_Action = NotPressed;
                IR3_Action = NotPressed;
                break;
            case 2:
                if(IR2_Action == NotPressed){
                    LED_TOG(LED_1);
                    IR2_Action = Pressed;
                }
                IR1_Action = NotPressed;
                IR3_Action = NotPressed;
                break;
            case 3:
                if(IR1_Action == NotPressed){
                    LED_TOG(LED_0);
                    IR1_Action = Pressed;
                }
                if(IR2_Action == NotPressed){
                    LED_TOG(LED_1);
                    IR2_Action = Pressed;
                }
                IR3_Action = NotPressed;
                break;
            case 4:
                if(IR3_Action == NotPressed){
                    LED_TOG(LED_2);
                    IR3_Action = Pressed;
                }
                IR1_Action = NotPressed;
                IR2_Action = NotPressed;
                break;
            case 5:
                if(IR1_Action == NotPressed){
                    LED_TOG(LED_0);
                    IR1_Action = Pressed;
                }
                if(IR3_Action == NotPressed){
                    LED_TOG(LED_2);
                    IR3_Action = Pressed;
                }
                IR2_Action = NotPressed;
                break;
            case 6:
                if(IR2_Action == NotPressed){
                    LED_TOG(LED_1);
                    IR2_Action = Pressed;
                }
                if(IR3_Action == NotPressed){
                    LED_TOG(LED_2);
                    IR3_Action = Pressed;
                }
                IR1_Action = NotPressed;
                break;
            case 7:
                if(IR1_Action == NotPressed){
                    LED_TOG(LED_0);
                    IR1_Action = Pressed;
                }
                if(IR2_Action == NotPressed){
                    LED_TOG(LED_1);
                    IR2_Action = Pressed;
                }
                if(IR3_Action == NotPressed){
                    LED_TOG(LED_2);
                    IR3_Action = Pressed;
                }
                break;
            default:
                IR1_Action = NotPressed;
                IR2_Action = NotPressed;
                IR3_Action = NotPressed;
                break;
        }
        u8 customKey = KEY_PAD_READ();
        if(customKey == '.' && DoorState == OPENED_DOOR){
            LCD_CLR();
            LCD_SEND_STR((u8*)"new password:");
            reset=TRUE;
        }else if(customKey && reset){
            if(ResetCounter == 0){
                LCD_CLR();
            }
            NewPassword[ResetCounter] = customKey;
            LCD_SEND_CHR(customKey);
            ResetCounter++;
        }
        if(customKey && !reset && !(customKey == '=' && !reset && DoorState == OPENED_DOOR)){
            if(PasswordCounter == 0){
                LCD_CLR();
            }
            EnteredPassword[PasswordCounter] = customKey;
            LCD_SEND_CHR(customKey);
            PasswordCounter++;
        }
        if(customKey == '=' && !reset && DoorState == OPENED_DOOR){
            //CloseDoor();
            DoorState = CLOSED_DOOR;
        }
        if(PasswordCounter == 4){
            PasswordCounter=0;
            LCD_CLR();
            if(CompareStrings(EnteredPassword, Password)){
                LCD_SEND_STR((u8*)"correct");
                //OpenDoor();
                DoorState = OPENED_DOOR;
            }else{
                LCD_SEND_STR((u8*)"failed");
            }
        }
        if(ResetCounter == 4){
            NewPassword[ResetCounter] = '\0';
            ResetCounter = 0;
            AssignStrings(Password, NewPassword);
            LCD_CLR();
            reset=FALSE;
            LCD_SEND_STR((u8*)"new:");
            LCD_SEND_STR(Password);
        }
        if(FLAME_READ_ALL() == FIRE_DETECTED){
            LED_OFF(LED_0);
            LED_OFF(LED_1);
            LED_OFF(LED_2);
            //OpenDoor();
            DoorState = OPENED_DOOR;
            while(FLAME_READ_ALL() == FIRE_DETECTED){
                //LED_TOG(Led_arr,ALARM);
                BUZZER_ONCE();
                _delay_ms(200);
            }
            //CloseDoor();
            DoorState = CLOSED_DOOR;
            BUZZER_OFF();
        }
    }
}
