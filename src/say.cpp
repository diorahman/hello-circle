#include <openssl/ssl.h>

#include "hello/say.h"
#include <iostream>

namespace Hello {

Say::Say() {

}

Say::~Say() {

}

void Say::boom() {
    std::cout << "Say!" << SSLeay_version(SSLEAY_VERSION) << std::endl;
}

}
