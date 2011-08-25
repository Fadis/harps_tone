/***************************************************************************
 *   Copyright (C) 2009 by Naomasa Matsubayashi   *
 *   harps@quaternion.sakura.ne.jp   *
 *                                                                         *
 *   All rights reserved.                                                  *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *   modification, are permitted provided that the following conditions    *
 *   are met:                                                              *
 *     * Redistributions of source code must retain the above copyright    *
 *       notice, this list of conditions and the following disclaimer.     *
 *     * Redistributions in binary form must reproduce the above copyright *
 *       notice, this list of conditions and the following disclaimer in   *
 *       the documentation and/or other materials provided with the        *
 *       distribution.                                                     *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR *
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 *   OWNER OR                                                              *
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, *
 *   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,   *
 *   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR    *
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY   *
 *   OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE *
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *
 ***************************************************************************/

#include <harps/compornent/dynamic_module.hpp>
#include <harps/compornent/generator.hpp>
#include <harps/compornent/scale.hpp>
#include <harps/compornent/touch.hpp>
#include <harps/compornent/constant.hpp>
#include <harps/compornent/add.hpp>
#include <harps/compornent/mul.hpp>
#include <harps/compornent/constant_mul.hpp>
#include <harps/compornent/sine.hpp>
#include <harps/compornent/triangle.hpp>
#include <harps/compornent/distotion.hpp>
#include <harps/compornent/envelope.hpp>
#include <harps/compornent/fm.hpp>

namespace harps {
  namespace compornent {
  typedef
    Touch<
      Add<
        Scale<
          FM<
            Generator< TONE >,
            Scale<
              ConstantMul<
                FM<
                  Generator< TONE >,
                  Scale<
                    ConstantMul<
                      FM<
                        Generator< TONE >,
                        Scale<
                          ConstantMul<
                            FM<
                              Generator< TONE >,
                              Constant< 0 >
                            >,
                            500 * 11/20
                          >,
                          3000
                        >
                      >,
                      450 * 11/20
                    >,
                    997
                  >
                >,
                450 * 11/20
              >,
              1002
            >,
            KEY, 0, 50, 0, 200, 700, 500 
          >,
          999
        >,
        Scale<
          FM<
            Generator< TONE >,
            Scale<
              ConstantMul<
                FM<
                  Generator< TONE >,
                  Scale<
                    ConstantMul<
                      FM<
                        Generator< TONE >,
                        Scale<
                          ConstantMul<
                            FM<
                              Generator< TONE >,
                              Constant< 0 >
                            >,
                            500 * 11/20
                          >,
                          3001
                        >
                      >,
                      450 * 11/20
                    >,
                    1002
                  >
                >,
                450 * 11/20
              >,
              999
            >,
            KEY, 0, 50, 0, 200, 700, 300 
          >,
          1001
        >
      >
    > Strings;
    typedef
      Mul<
        Strings,
        Add< ConstantMul< Scale< Sine< Generator< LOCAL > >, 4000 >, 250 >, Constant< 750 > >
      > ToremoroStrings;
  }
}

HARPS_DYNAMIC_MODULE_SOCKET( harps::compornent::ToremoroStrings )
