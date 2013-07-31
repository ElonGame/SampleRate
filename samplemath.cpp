#include "samplemath.h"

#include <math.h>

// Works using BPM in place of sample rate.
int ValueFromSemitoneShift( double semitones, unsigned int samplerate )
{
    double multiplier = pow( 2.0, (semitones / 12.0 ));
    double result = samplerate * multiplier;
    int retval = (int)result;
    // Fix any rounding errors that will happen upon int conversion.
    if( (result - (double)retval ) > 0.5f )
    {
        retval++;
    }
    return retval;
}

// Works using BPM in place of sample rate.
double DoubleValueFromSemitoneShift( double semitones, unsigned int samplerate )
{
    double multiplier = pow( 2.0, (semitones / 12.0 ));
    return (samplerate * multiplier);
}

// Works using old and new BPM in calculations too.
int SemitoneShiftFromRatio( int oldpitch, int newpitch )
{
    if( oldpitch == 0 || newpitch == 0 )
    {
        return 0;
    }
    double ratio = (double)newpitch / (double)oldpitch;
    // Do a base 2 log.  We do this by taking the natural log and dividing it by the base2 log.
    double factor = log(ratio) / log(2.0);
    double result = factor * 12;
    int retval = (int)result;
    if( (result - (double)retval ) > 0.5f )
    {
        retval++;
    }
    return retval;
}

// Works using old and new BPM in calculations too.
double DoubleSemitoneShiftFromRatio( double oldpitch, double newpitch )
{
    if( oldpitch == 0.0 || newpitch == 0.0 )
    {
        return 0.0;
    }
    double ratio = newpitch / oldpitch;
    // Do a base 2 log.  We do this by taking the natural log and dividing it by the base2 log.
    double factor = log(ratio) / log(2.0);
    return factor * 12;
}

