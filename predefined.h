#pragma once

/*
This software is part of libcsdr, a set of simple DSP routines for 
Software Defined Radio.

Copyright (c) 2014, Andras Retzler <randras@sdr.hu>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANDRAS RETZLER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


//predefined large arrays come here

//De-emphasis FIR filters:
//I chose not to implement a filter design algoritm for these, because:
// - they are defined by their frequency envelope, and I didn't want to implement the least squares or similar algorithm to design such filters
// - they are most likely needed at given fixed sample rates

/*octave>
	
function mkdeemph(sr,tapnum,norm_freq) 
	% Make NFM deemphasis filter. Parameters: samplerate, filter length, frequency to normalize at (filter gain will be 0dB at this frequency)
	normalize_at_freq = @(vect,freq) vect/dot(vect,sin(2*pi*freq*[0:1/sr:size(vect)(1)/sr])); 
	freqvect=[0,200, 200,400, 400,3700, 3700,sr/2];
	coeffs=firls(tapnum,freqvect/(sr/2),[0,0,0,1,1,0.1,0,0]);
	coeffs=normalize_at_freq(coeffs,norm_freq);
	freqz(coeffs);
	printf("%g, ",coeffs);
	printf("\n")
end 

mkdeemph(48000,199,500)
	
*/

float deemphasis_nfm_predefined_fir_48000[] = 
{ 0.00172568, 0.00179665, 0.00191952, 0.00205318, 0.00215178, 0.00217534, 0.00209924, 0.00192026, 0.00165789, 0.0013502, 0.00104545, 0.000790927, 0.000621911, 0.000553077, 0.000574554, 0.000653624, 0.000741816, 0.000785877, 0.000740151, 0.000577506, 0.000296217, -7.89273e-05, -0.0005017, -0.000914683, -0.00126243, -0.00150456, -0.00162564, -0.0016396, -0.00158725, -0.00152751, -0.00152401, -0.00163025, -0.00187658, -0.00226223, -0.00275443, -0.003295, -0.0038132, -0.00424193, -0.00453375, -0.00467274, -0.00467943, -0.00460728, -0.00453119, -0.00453056, -0.00467051, -0.00498574, -0.00547096, -0.00608027, -0.00673627, -0.00734698, -0.00782705, -0.00811841, -0.00820539, -0.00812057, -0.00793936, -0.00776415, -0.00770111, -0.00783479, -0.00820643, -0.00880131, -0.00954878, -0.0103356, -0.0110303, -0.011514, -0.0117094, -0.0116029, -0.0112526, -0.0107795, -0.010343, -0.0101053, -0.0101917, -0.0106561, -0.0114608, -0.0124761, -0.0135018, -0.0143081, -0.0146885, -0.0145126, -0.0137683, -0.0125796, -0.0111959, -0.00994914, -0.00918404, -0.00917447, -0.0100402, -0.0116822, -0.0137533, -0.0156723, -0.0166881, -0.0159848, -0.0128153, -0.00664117, 0.00274383, 0.0151313, 0.0298729, 0.0459219, 0.0619393, 0.076451, 0.0880348, 0.0955087, 0.098091, 0.0955087, 0.0880348, 0.076451, 0.0619393, 0.0459219, 0.0298729, 0.0151313, 0.00274383, -0.00664117, -0.0128153, -0.0159848, -0.0166881, -0.0156723, -0.0137533, -0.0116822, -0.0100402, -0.00917447, -0.00918404, -0.00994914, -0.0111959, -0.0125796, -0.0137683, -0.0145126, -0.0146885, -0.0143081, -0.0135018, -0.0124761, -0.0114608, -0.0106561, -0.0101917, -0.0101053, -0.010343, -0.0107795, -0.0112526, -0.0116029, -0.0117094, -0.011514, -0.0110303, -0.0103356, -0.00954878, -0.00880131, -0.00820643, -0.00783479, -0.00770111, -0.00776415, -0.00793936, -0.00812057, -0.00820539, -0.00811841, -0.00782705, -0.00734698, -0.00673627, -0.00608027, -0.00547096, -0.00498574, -0.00467051, -0.00453056, -0.00453119, -0.00460728, -0.00467943, -0.00467274, -0.00453375, -0.00424193, -0.0038132, -0.003295, -0.00275443, -0.00226223, -0.00187658, -0.00163025, -0.00152401, -0.00152751, -0.00158725, -0.0016396, -0.00162564, -0.00150456, -0.00126243, -0.000914683, -0.0005017, -7.89273e-05, 0.000296217, 0.000577506, 0.000740151, 0.000785877, 0.000741816, 0.000653624, 0.000574554, 0.000553077, 0.000621911, 0.000790927, 0.00104545, 0.0013502, 0.00165789, 0.00192026, 0.00209924, 0.00217534, 0.00215178, 0.00205318, 0.00191952, 0.00179665, 0.00172568 };

//mkdeemph(8000,79,500)
float deemphasis_nfm_predefined_fir_8000[] = 
{ 1.43777e+11, 1.45874e+11, -4.67746e+11, 9.98433e+10, -1.47835e+12, -3.78799e+11, -2.61333e+12, -1.07042e+12, -3.41242e+12, -1.57042e+12, -3.34195e+12, -1.4091e+12, -1.96864e+12, -2.26212e+11, 8.48259e+11, 2.04875e+12, 4.80451e+12, 5.06875e+12, 9.09434e+12, 8.04571e+12, 1.24874e+13, 9.85837e+12, 1.35433e+13, 9.28407e+12, 1.09287e+13, 5.30975e+12, 3.76762e+12, -2.54809e+12, -8.06152e+12, -1.39895e+13, -2.37664e+13, -2.77865e+13, -4.16745e+13, -4.16797e+13, -5.94708e+13, -5.17628e+13, -7.46014e+13, -4.66449e+13, -8.47575e+13, 1.51722e+14, 4.98196e+14, 1.51722e+14, -8.47575e+13, -4.66449e+13, -7.46014e+13, -5.17628e+13, -5.94708e+13, -4.16797e+13, -4.16745e+13, -2.77865e+13, -2.37664e+13, -1.39895e+13, -8.06152e+12, -2.54809e+12, 3.76762e+12, 5.30975e+12, 1.09287e+13, 9.28407e+12, 1.35433e+13, 9.85837e+12, 1.24874e+13, 8.04571e+12, 9.09434e+12, 5.06875e+12, 4.80451e+12, 2.04875e+12, 8.48259e+11, -2.26212e+11, -1.96864e+12, -1.4091e+12, -3.34195e+12, -1.57042e+12, -3.41242e+12, -1.07042e+12, -2.61333e+12, -3.78799e+11, -1.47835e+12, 9.98433e+10, -4.67746e+11, 1.45874e+11, 1.43777e+11 };

