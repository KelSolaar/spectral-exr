#pragma once

namespace SEXR {

enum SpectrumType {
    UNDEFINED  = 0             , // 0b0000
    REFLECTIVE = 2             , // 0b0001
    EMISSIVE   = 4             , // 0b0010
    BISPECTRAL = 8 | REFLECTIVE, // 0b0101
    POLARISED  = 16              // 0b1000
};


inline SpectrumType operator|(SpectrumType a, SpectrumType b)
{
    return static_cast<SpectrumType>(static_cast<int>(a) | static_cast<int>(b));
}

inline SpectrumType operator^(SpectrumType a, SpectrumType b)
{
  return static_cast<SpectrumType>(static_cast<int>(a) ^ static_cast<int>(b));
}

inline bool isReflective(SpectrumType s)
{
  return (s & REFLECTIVE) == REFLECTIVE;
}

inline bool isEmissive(SpectrumType s)
{
  return (s & EMISSIVE) == EMISSIVE;
}

inline bool isPolarised(SpectrumType s)
{
  return (s & POLARISED) == POLARISED;
}

inline bool isBispectral(SpectrumType s)
{
  return (s & BISPECTRAL) == BISPECTRAL;
}

} // namespace SEXR
