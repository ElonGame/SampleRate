#ifndef _SAMPLEMATH_H_
#define _SAMPLEMATH_H_

int ValueFromSemitoneShift( double semitones, unsigned int samplerate );
double DoubleValueFromSemitoneShift( double semitones, unsigned int samplerate );
int SemitoneShiftFromRatio( int oldpitch, int newpitch );
double DoubleSemitoneShiftFromRatio( double oldpitch, double newpitch );

#endif

