/**
 * Copyright (c) 2020 - 2021
 * Alban Fichet, Romain Pacanowski, Alexander Wilkie
 * Institut d'Optique Graduate School, CNRS - Universite de Bordeaux,
 * Inria, Charles University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided
 * with the distribution.
 *  * Neither the name of Institut d'Optique Graduate School, CNRS -
 * Universite de Bordeaux, Inria, Charles University nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <vector>
#include <OpenEXR/ImfStandardAttributes.h>

namespace SEXR
{
    class SpectrumAttribute
    {
      public:
        enum Error
        {
            NOT_SAME_VECTOR_SIZE,
            PARSING_ERROR
        };

        SpectrumAttribute();

        SpectrumAttribute(
          std::vector<float> wavelengths_nm, std::vector<float> values);

        SpectrumAttribute(const Imf::StringAttribute &attributeValue);

        Imf::StringAttribute getAttribute() const;

        std::vector<float> &      wavelengths_nm() { return _wavelengths_nm; }
        const std::vector<float> &wavelengths_nm() const
        {
            return _wavelengths_nm;
        }

        std::vector<float> &      values() { return _values; }
        const std::vector<float> &values() const { return _values; }

        float &      wavelength_nm(size_t i) { return _wavelengths_nm[i]; }
        const float &wavelength_nm(size_t i) const
        {
            return _wavelengths_nm[i];
        }

        float &      value(size_t i) { return _values[i]; }
        const float &value(size_t i) const { return _values[i]; }

        size_t size() const { return _wavelengths_nm.size(); }

      protected:
        std::vector<float> _wavelengths_nm;
        std::vector<float> _values;
    };

}   // namespace SEXR
