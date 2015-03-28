#include "Logging.h"

void Logging::Init(int level, long baud){
    _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOG_LEVEL_VERBOSE);
    _baud = baud;
    Serial.begin(_baud);
}

void Logging::Error(char* msg, ...){
    if (LOG_LEVEL_ERRORS <= _level) {   
		print ("ERROR: ",0);
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Error(const __FlashStringHelper* msg, ...){
    if (LOG_LEVEL_ERRORS <= _level) {   
		print ("ERROR: ",0);
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::Info(char* msg, ...){
    if (LOG_LEVEL_INFOS <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Info(const __FlashStringHelper* msg, ...){
    if (LOG_LEVEL_INFOS <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Debug(char* msg, ...){
    if (LOG_LEVEL_DEBUG <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Debug(const __FlashStringHelper* msg, ...){
    if (LOG_LEVEL_DEBUG <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::Verbose(char* msg, ...){
    if (LOG_LEVEL_VERBOSE <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Verbose(const __FlashStringHelper* msg, ...){
    if (LOG_LEVEL_VERBOSE <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::setLogLevel(int logLevel) {
	_level = logLevel % 5;
}

int Logging::getLogLevel() {
	return _level;
}

 void Logging::print(const char *format, va_list args) {
    //
    // loop through format string
    for (; *format != 0; ++format) {
        if (*format == '%') {
            ++format;
            if (*format == '\0') break;
            if (*format == '%') {
                Serial.print(*format);
                continue;
            }
            if( *format == 's' ) {
				register char *s = (char *)va_arg( args, int );
				Serial.print(s);
				continue;
			}
            if( *format == 'd' || *format == 'i') {
				Serial.print(va_arg( args, int ),DEC);
				continue;
			}
            if( *format == 'x' ) {
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'X' ) {
				Serial.print("0x");
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'b' ) {
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'B' ) {
				Serial.print("0b");
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'l' ) {
				Serial.print(va_arg( args, long ),DEC);
				continue;
			}

            if( *format == 'c' ) {
				Serial.print(va_arg( args, int ));
				continue;
			}
            if( *format == 't' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("T");
				}
				else {
					Serial.print("F");				
				}
				continue;
			}
            if( *format == 'T' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("true");
				}
				else {
					Serial.print("false");				
				}
				continue;
			}

        }
        Serial.print(*format);
    }
 }

 void Logging::print(const __FlashStringHelper *format, va_list args) {
	 const char PROGMEM *p = (const char PROGMEM *)format;
	  size_t n = 0;
	  while (1) {
		unsigned char c = pgm_read_byte(p++);
		if (c == '%') {
			c = pgm_read_byte(p++);
			if (c == '\0') break;
            if (c == '%') {
                Serial.write(c);
                continue;
            }
            if( c == 's' ) {
				register char *s = (char *)va_arg( args, int );
				Serial.write(s);
				continue;
			}
            if( c == 'd' || c == 'i') {
				Serial.print(va_arg( args, int ),DEC);
				continue;
			}
            if( c == 'x' ) {
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( c == 'X' ) {
				Serial.print("0x");
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( c == 'b' ) {
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( c == 'B' ) {
				Serial.print("0b");
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( c == 'l' ) {
				Serial.print(va_arg( args, long ),DEC);
				continue;
			}

            if( c == 'c' ) {
				Serial.print(va_arg( args, int ));
				continue;
			}
            if( c == 't' ) {
				if (va_arg( args, int ) == 1) {
					Serial.write("T");
				}
				else {
					Serial.write("F");				
				}
				continue;
			}
            if( c == 'T' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("true");
				}
				else {
					Serial.print("false");				
				}
				continue;
			}
		}
		
		if (c == 0) break;
		n += Serial.write(c);
	  }
 }
 
 Logging Log = Logging();