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
    Scale<
      FM<
        Generator< TONE >,
        FM<
          Generator< TONE >,
          Mul< Scale< FM< Generator< TONE >, Constant< 0 >, KEY, 0, 0, 0, 500, 0, 10 >, 2000 >, Constant< 200 > >,
          KEY, 0, 0, 0, 500, 100, 10
        >,
        KEY, 0, 0, 0, 1500, 200, 10
      >,
      500
    > Guiter;
/*
  typedef
    Scale<
      FM<
        Generator< TONE >,
        FM<
          Generator< TONE >,
          Scale< Mul< FM< Generator< TONE >, Constant< 0 >, KEY, 0, 0, 0, 300, 500, 300 >, Constant< 250 > >, 1000 >,
          KEY, 0, 40, 0, 500, 400, 300
        >,
        KEY, 0, 0, 0, 1000, 800, 600
      >,
      250
    > Guiter;*/
  typedef
    Distotion<
      Touch< Guiter >,
      0, 60, 80
    > DistGuiter;
  }
}

HARPS_DYNAMIC_MODULE_SOCKET( harps::compornent::DistGuiter )
