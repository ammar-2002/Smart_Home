#include "DIO.h"
#include "MCAL/REG.h"
#include "APP/LIB/BIT_MATH.h"

void PIN_MODE(u8 x,u8 state){
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(port){
		case 0:
		switch(state){
			case INPUT:
			CLR_BIT(DDRA,pin);
			break;
			case OUTPUT:
			SET_BIT(DDRA,pin);
			break;
			default:
			break;
		}
		break;
		case 1:
		switch(state){
			case INPUT:
			CLR_BIT(DDRB,pin);
			break;
			case OUTPUT:
			SET_BIT(DDRB,pin);
			break;
			default:
			break;
		}
		break;
		case 2:
		switch(state){
			case INPUT:
			CLR_BIT(DDRC,pin);
			break;
			case OUTPUT:
			SET_BIT(DDRC,pin);
			break;
			default:
			break;
		}
		break;
		case 3:
		switch(state){
			case INPUT:
			CLR_BIT(DDRD,pin);
			break;
			case OUTPUT:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
void PIN_WRITE(u8 x,u8 state){
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(port){
		case 0:
		switch(state){
			case LOW:
			CLR_BIT(PORTA,pin);
			break;
			case HIGH:
			SET_BIT(PORTA,pin);
			break;
			default:
			break;
		}
		break;
		case 1:
		switch(state){
			case LOW:
			CLR_BIT(PORTB,pin);
			break;
			case HIGH:
			SET_BIT(PORTB,pin);
			break;
			default:
			break;
		}
		break;
		case 2:
		switch(state){
			case LOW:
			CLR_BIT(PORTC,pin);
			break;
			case HIGH:
			SET_BIT(PORTC,pin);
			break;
			default:
			break;
		}
		break;
		case 3:
		switch(state){
			case LOW:
			CLR_BIT(PORTD,pin);
			break;
			case HIGH:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

u8 PIN_READ(u8 x){
	u8 pin  = x % 10;
	u8 port = x / 10;
	u8 reading = 0;
	switch(port){
		case 0:
		reading = GET_BIT(PINA,pin);
		break;
		case 1:
		reading = GET_BIT(PINB,pin);
		break;
		case 2:
		reading = GET_BIT(PINB,pin);
		break;
		case 3:
		reading = GET_BIT(PINB,pin);
		break;
		default:
		break;
	}
	return reading;
}

void PIN_TOG(u8 x){
	u8 pin  = x % 10;
	u8 port = x / 10;
	switch(port){
		case 0:
		TOG_BIT(PORTA,pin);
		break;
		case 1:
		TOG_BIT(PORTB,pin);
		break;
		case 2:
		TOG_BIT(PORTC,pin);
		break;
		case 3:
		TOG_BIT(PORTD,pin);
		break;
		default:
		break;
	}
}

void PORT_MODE(u8 port,u8 state){
	switch(port){
		case A:
		switch(state){
			case OUTPUT:
			DDRA = 255;
			break;
			case INPUT:
			DDRA = 0;
			break;
			default:
			break;
		}
		break;
		case B:
		switch(state){
			case OUTPUT:
			DDRB = 255;
			break;
			case INPUT:
			DDRB = 0;
			break;
			default:
			break;
		}
		break;
		case C:
		switch(state){
			case OUTPUT:
			DDRC = 255;
			break;
			case INPUT:
			DDRC = 0;
			break;
			default:
			break;
		}
		break;
		case D:
		switch(state){
			case OUTPUT:
			DDRD = 255;
			break;
			case INPUT:
			DDRD = 0;
			break;
			default:
			break;
		}
		break;
	}
}

void PORT_WRITE(u8 port,u8 value){
	switch(port){
		case A:
		PORTA = value;
		break;
		case B:
		PORTB = value;
		break;
		case C:
		PORTC = value;
		break;
		case D:
		PORTD = value;
		break;
	}
}

u8 PORT_READ(u8 port){
	u8 value=0;
	switch(port){
		case A:
		value = PORTA;
		break;
		case B:
		value = PORTB;
		break;
		case C:
		value = PORTC;
		break;
		case D:
		value = PORTD;
		default:
		break;
	}
	return value;
}

void PIN_PULL_UP_RES(u8 x,u8 state){
    u8 pin  = x % 10;
    u8 port = x / 10;
    switch(port){
        case 0:
        switch(state){
            case DISABLE:
            CLR_BIT(PORTA,pin);
            break;
            case ENABLE:
            SET_BIT(PORTA,pin);
            break;
            default:
            break;
        }
        break;
        case 1:
        switch(state){
            case DISABLE:
            CLR_BIT(PORTB,pin);
            break;
            case ENABLE:
            SET_BIT(PORTB,pin);
            break;
            default:
            break;
        }
        break;
        case 2:
        switch(state){
            case DISABLE:
            CLR_BIT(PORTC,pin);
            break;
            case ENABLE:
            SET_BIT(PORTC,pin);
            break;
            default:
            break;
        }
        break;
        case 3:
        switch(state){
            case DISABLE:
            CLR_BIT(PORTD,pin);
            break;
            case ENABLE:
            SET_BIT(PORTD,pin);
            break;
            default:
            break;
        }
        break;
        default:
        break;
    }
}