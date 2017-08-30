///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, Tadas Baltrusaitis, all rights reserved.
//
// ACADEMIC OR NON-PROFIT ORGANIZATION NONCOMMERCIAL RESEARCH USE ONLY
//
// BY USING OR DOWNLOADING THE SOFTWARE, YOU ARE AGREEING TO THE TERMS OF THIS LICENSE AGREEMENT.  
// IF YOU DO NOT AGREE WITH THESE TERMS, YOU MAY NOT USE OR DOWNLOAD THE SOFTWARE.
//
// License can be found in OpenFace-license.txt
//
//     * Any publications arising from the use of this software, including but
//       not limited to academic journal and conference publications, technical
//       reports and manuals, must cite at least one of the following works:
//
//       OpenFace: an open source facial behavior analysis toolkit
//       Tadas Baltru�aitis, Peter Robinson, and Louis-Philippe Morency
//       in IEEE Winter Conference on Applications of Computer Vision, 2016  
//
//       Rendering of Eyes for Eye-Shape Registration and Gaze Estimation
//       Erroll Wood, Tadas Baltru�aitis, Xucong Zhang, Yusuke Sugano, Peter Robinson, and Andreas Bulling 
//       in IEEE International. Conference on Computer Vision (ICCV),  2015 
//
//       Cross-dataset learning and person-speci?c normalisation for automatic Action Unit detection
//       Tadas Baltru�aitis, Marwa Mahmoud, and Peter Robinson 
//       in Facial Expression Recognition and Analysis Challenge, 
//       IEEE International Conference on Automatic Face and Gesture Recognition, 2015 
//
//       Constrained Local Neural Fields for robust facial landmark detection in the wild.
//       Tadas Baltru�aitis, Peter Robinson, and Louis-Philippe Morency. 
//       in IEEE Int. Conference on Computer Vision Workshops, 300 Faces in-the-Wild Challenge, 2013.    
//
///////////////////////////////////////////////////////////////////////////////

//  Header for all external CLNF/CLM-Z/CLM methods of interest to the user
#ifndef __CNN_UTILS_h_
#define __CNN_UTILS_h_

// OpenCV includes
#include <opencv2/core/core.hpp>

using namespace std;

namespace LandmarkDetector
{
	//===========================================================================	
	// Various CNN layers

	// Parametric ReLU with leaky weights (separate ones per channel)
	void PReLU(std::vector<cv::Mat_<float> >& input_output_maps, cv::Mat_<float> prelu_weights);

	// The fully connected layer
	void fully_connected(std::vector<cv::Mat_<float> >& outputs, const std::vector<cv::Mat_<float> >& input_maps, cv::Mat_<float> weights, cv::Mat_<float> biases);

	// Max pooling layer with parametrized stride and kernel sizes
	void max_pooling(std::vector<cv::Mat_<float> >& outputs, const std::vector<cv::Mat_<float> >& input_maps, int stride_x, int stride_y, int kernel_size_x, int kernel_size_y);

	// Convolution using FFT optimization rather than matrix multiplication
	void convolution_fft2(std::vector<cv::Mat_<float> >& outputs, const std::vector<cv::Mat_<float> >& input_maps, const std::vector<std::vector<cv::Mat_<float> > >& kernels, const std::vector<float >& biases, vector<map<int, vector<cv::Mat_<double> > > >& precomp_dfts);
	
	// Convolution using matrix multiplication and OpenBLAS optimization
	void convolution_direct_blas(std::vector<cv::Mat_<float> >& outputs, const std::vector<cv::Mat_<float> >& input_maps, const cv::Mat_<float>& weight_matrix, const std::vector<float >& biases, int height_k, int width_k);

}
#endif