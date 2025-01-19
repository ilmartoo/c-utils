#include "arena.h"
#include "test.h"

void ArenaTests(void)
{
    TestGroup("arena.h arena.c", {
        TestCase("Zero intialization", {
            size_t size = 400;
            Arena arena = ArenaCreate();
            void* abc = ArenaPushZero(&arena, size);

            AssertMemZero("The reserved space should be initialized to 0", abc, size);
        });
    });
}
