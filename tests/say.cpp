#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "hello/say.h"

using namespace Hello;

SCENARIO("Say hello") {
    GIVEN("say") {
        auto say = new Say();
        Say::boom();
        REQUIRE(say != nullptr);
        delete say;
    }
}
