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
#include <harps/compornent/triangle.hpp>
#include <harps/compornent/scale.hpp>
#include <harps/compornent/constant_mul.hpp>
#include <harps/compornent/touch.hpp>
#include <harps/compornent/constant.hpp>
#include <harps/compornent/add.hpp>
#include <harps/compornent/fm.hpp>
#include <harps/compornent/noize.hpp>

namespace harps {
  namespace compornent {
    /*
  typedef
    Touch< Add<
      FM<
        Generator< TONE >,
        Constant< 0 >,
        KEY, 0, 35, 0, 0, 1000, 200
      >,
      Scale<
        FM<
          Generator< TONE >,
          Constant< 0 >,
          KEY, 0, 30, 0, 0, 1000, 200
        >,
        3000
      >,
      Scale<
        FM<
          Generator< TONE >,
          Constant< 0 >,
          KEY, 0, 36, 0, 0, 1000, 200
        >,
        5000
      >,
      Scale<
        FM<
          Generator< TONE >,
          Constant< 0 >,
          KEY, 0, 40, 0, 0, 1000, 200
        >,
        7000
      >
    > > Clarinet;
    */
  typedef
    Touch<
      Scale<
      Mul<
        Add<
          FM2<
            Triangle< Generator< TONE > >,
            Noize< 30, 20 >,
            KEY,
            0,
            70, 40, 500,
            10, 1000,
            10, 4, 950,
            900,
            400, 200, 850,
            800,
            40, 20, 300
          >,
          Scale<
            FM2<
              Generator< TONE >,
              Noize< 40, 0 >,
              KEY,
              0,
              60, 20, 500,
              10, 1000,
              10, 4, 950,
              900,
              400, 200, 850,
              800,
              40, 20, 300
            >,
            3000
          >,
          Scale<
            FM2<
              Generator< TONE >,
              Noize< 10, 0 >,
              KEY,
              0,
              72, 50, 500,
              10, 1000,
              10, 4, 950,
              900,
              400, 200, 850,
              700,
              40, 20, 300
            >,
            5000
          >,
          Scale<
            FM2<
              Generator< TONE >,
              Constant< 0 >,
              KEY,
              0,
              80, 60, 500,
              10, 1000,
              10, 4, 950,
              900,
              400, 200, 850,
              600,
              40, 20, 300
            >,
            7000
          >
        >,
        Add< ConstantMul< Scale< Sine< Generator< LOCAL > >, 8000 >, 250 >, Constant< 750 > >
      >, 500
    > > Clarinet;
/*    typedef
      Mul<
        Noize< 400, 150 >,
        Envelope2<
          KEY,
          0,
          40, 30, 500,
          10, 1000,
          800, 800, 500,
          500,
          800, 800, 0,
          0,
          800, 400, 500
        >
      > Clarinet;*/
  }
}

HARPS_DYNAMIC_MODULE_SOCKET( harps::compornent::Clarinet )
