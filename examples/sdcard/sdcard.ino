// uncommend NDEBUG disables ASSERT and all debug serial (Release Mode)
//#define NDEBUG

#include <DebugLog.h>

void shorten(String& s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ':')
            s.setCharAt(i, '_');
    }
}

void setup()
{
  Serial.begin(115200);
  delay(2000);

  if (SD.begin(BUILTIN_SDCARD))
  {
    PRINTLN("sd initialization success");

    String filename = "/" + String(__TIME__) + ".txt";
    shorten(filename);
    DEBUG_LOG_TO_SD(SD, filename, false); // 3rd arg: if only log to SD or not
  }
  else
    PRINTLN("sd initialization failed!");

  PRINT("this is for debug");
  PRINTLN(1, 2.2, "you can", "print variable args");
  PRINTLN("current log level is", (int)LOG_GET_LEVEL()); // 0: NONE, 1: ERRORS, 2: WARNINGS, 3: VERBOSE

  LOG_ERROR("this is error log");
  LOG_WARNING("this is warning log");
  LOG_VERBOSE("this is verbose log");

  LOG_SET_LEVEL(DebugLogLevel::WARNINGS);
  PRINTLN("change log level to WARNINGS");
  PRINTLN("current log level is", (int)LOG_GET_LEVEL());

  LOG_ERROR("this is error log");
  LOG_WARNING("this is warning log");
  LOG_VERBOSE("this is verbose log");

  LOG_SET_LEVEL(DebugLogLevel::ERRORS);
  PRINTLN("change log level to ERRORS");
  PRINTLN("current log level is", (int)LOG_GET_LEVEL());

  LOG_ERROR("this is error log");
  LOG_WARNING("this is warning log");
  LOG_VERBOSE("this is verbose log");

  LOG_SET_LEVEL(DebugLogLevel::NONE);
  PRINTLN("change log level to NONE");
  PRINTLN("current log level is", (int)LOG_GET_LEVEL());

  LOG_ERROR("this is error log");
  LOG_WARNING("this is warning log");
  LOG_VERBOSE("this is verbose log");

  delay(5000);

  int x = 1;
  ASSERT(x != 1); // if assertion failed, Serial endlessly prints message
}

void loop()
{
  PRINTLN("if NDEBUG is commented out (assert is enabled), does not come here");
  delay(1000);
}
