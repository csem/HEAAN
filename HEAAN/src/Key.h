/*
* Copyright (c) by CryptoLab inc.
* This program is licensed under a
* Creative Commons Attribution-NonCommercial 3.0 Unported License.
* You should have received a copy of the license along with this
* work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
*/
#ifndef HEAAN_KEY_H_
#define HEAAN_KEY_H_

#include <NTL/ZZ.h>
#include "Params.h"

#include <memory>

namespace heaan {

class Key {
public:

    std::unique_ptr<uint64_t[]> rax;
    std::unique_ptr<uint64_t[]> rbx;

    Key() {
        rax.reset(new uint64_t[heaan::Nnprimes]);
        rbx.reset(new uint64_t[heaan::Nnprimes]);
    }

    ~Key() = default;  // Automatic memory deletion

    // Move constructor (new)
    Key(Key&& other) noexcept {
        rax = std::move(other.rax);
        rbx = std::move(other.rbx);
    }	
};

}  // namespace heaan

#endif
