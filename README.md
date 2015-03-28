# Arduino-FlashStringHelperLogger
This library is a fork from the Arduino logging library. Support has been added for the FlashStringHelper data type which
enables the logging of strings (which can take up considerable space, especially when adding a lot of log statements) saved to
the flash program space memory (PROGMEM) instead of the scarce SRAM. This enables us to add a significant amount of
log statements while almost no scarce SRAM is needed.

## Usage
```cpp
#include <Logging.h>

/**
 * Initialization
 *
 * Setup logging, available is:
 * 0	LOG_LEVEL_NOOUTPUT	no output
 * 1	LOG_LEVEL_ERRORS	only errors
 * 2	LOG_LEVEL_INFOS	errors and info
 * 3	LOG_LEVEL_DEBUG	errors, info and debug
 * 4	LOG_LEVEL_VERBOSE	all
 *
 */
const int LOG_LEVEL = LOG_LEVEL_INFOS;
const long BAUD_RATE = 115200; // Serial transmission rate in bits per second;
Log.Init(LOG_LEVEL, BAUD_RATE);

/**
 * Usage
 */
// Debug logging, not shown since current log level is LOG_LEVEL_INFOS
Log.Debug(F("Pin %d selected as debug output pin\n"), 1);

// Log info, is shown since log level is LOG_LEVEL_INFOS
Log.Info(F("******************************************\n"));
Log.Info(F("Setup arduino complete\n"));
Log.Info(F("Initiating first stage...\n"));
Log.Info(F("******************************************\n"));
```

## Author
This library has been developed by [Wilbert van de Ridder](http://www.github.com/WRidder) for a BSc assignment at the [University of Twente](http://www.utwente.nl).