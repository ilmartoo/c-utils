#include "helpers.h"
#include "test.h"

void HelpersTests(void)
{
    TestGroup("helper.h", {
        TestCase("min()", {
            Assert("20 must be lower than 10", min(10, 20) == 10);
            Assert("-1 must be lower than 10", min(10, -1) == -1);
            Assert("0 must be lower than 10", min(10, 0) == 0);
            Assert("Must be 10", min(10, 10) == 10);
        });

        TestCase("max()", {
            Assert("20 must be bigger than 10", max(10, 20) == 20);
            Assert("10 must be bigger than -1", max(10, -1) == 10);
            Assert("-1 must be bigger than -2", max(-1, -2) == -1);
            Assert("Must be 10", max(10, 10) == 10);
        });

        TestCase("countof()", {
            struct Test {
                int a;
                float b;
                char c;
            };

            float arr1[1] = { 0 };
            struct Test arr10[10] = { 0 };
            char arr255[255] = { 0 };

            Assert("Must be length = 1", countof(arr1) == 1);
            Assert("Must be length = 10", countof(arr10) == 10);
            Assert("Must be length = 255", countof(arr255) == 255);
        });

        TestCase("lengthof()", {
            char strEmpty[] = "";
            char strHello[] = "Hello its me mario";

            Assert("Must be length = 0", lengthof(strEmpty) == 0);
            Assert("Must be length = 18", lengthof(strHello) == 18);
        });
    });
}
