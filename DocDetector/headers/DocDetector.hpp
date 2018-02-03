#pragma once

#include <opencv2/core.hpp>

//********************************
//********** Unity Link **********
//********************************
/// <summary>
/// Documents detector.
/// </summary>
/// <param name="in">Unity Image.</param>
/// <param name="out">Documents definition for Unity.</param>
void DocDetector(/*const image unity en entr�e& in, */ std::vector<int> &out);

//******************************
//********** Computes **********
//******************************
/// <summary>
/// Unity frame to OpenCV Mat.
/// </summary>
/// <param name="in">Unity Image.</param>
/// <param name="dst">tri-channel 8-bit image.</param>
void UnityToOpenCVMat(/*const image unity en entr�e& in,*/ cv::Mat &dst);

/// <summary>
/// Docses to unity.
/// </summary>
/// <param name="docs">Vector of Documents. Each doc is represented by a 8-elements vector \f$(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4)\f$,
/// where \f$(x_1,y_1)\f$, \f$(x_2, y_2)\f$, \f$(x_3, y_3)\f$ and \f$(x_4, y_4)\f$ are the corner of each detected Document.</param>
/// <param name="dst">The DST.</param>
void DocsToUnity(std::vector<cv::Vec8i> &docs, std::vector<int> &dst);

/// <summary>
/// Binary edge detector.
/// </summary>
/// <param name="src">single or tri-channel 8-bit input image.</param>
/// <param name="dst">8-bit, single-channel binary image.</param>
/// <param name="min_tresh">first threshold for the hysteresis procedure.</param>
/// <param name="max_tresh">second threshold for the hysteresis procedure.</param>
/// <param name="aperture">aperture size for the Sobel operator.</param>
void BinaryEdgeDetector(const cv::Mat &src, cv::Mat &dst,
                        int min_tresh = 100, int max_tresh = 205, int aperture = 3);

/// <summary>
/// Lines detector.
/// </summary>
/// <param name="src">8-bit, single-channel binary source image. The image can't be modified by the function.</param>
/// <param name="lines">Output vector of lines. Each line is represented by a 4-element vector \f$(x_1, y_1, x_2, y_2)\f$,
/// where \f$(x_1,y_1)\f$ and \f$(x_2, y_2)\f$ are the ending points of each detected line segment.</param>
/// <param name="rho">Distance resolution of the accumulator in pixels.</param>
/// <param name="theta">Angle resolution of the accumulator in radians.</param>
/// <param name="threshold">Accumulator threshold parameter. Only those lines are returned that get enough votes (>threshold).</param>
/// <param name="minLineLength"> Minimum line length. Line segments shorter than that are rejected.</param>
/// <param name="maxLineGap">Maximum allowed gap between points on the same line to link them.</param>
void LinesDetector(const cv::Mat &src, std::vector<cv::Vec4i> &lines,
                   double rho = 1, double theta = CV_PI / 180, int threshold = 50,
                   double minLineLength = 30, double maxLineGap = 30);

/// <summary>
/// Lines to docs detection.
/// </summary>
/// <param name="lines">Vector of lines. Each line is represented by a 4-element vector \f$(x_1, y_1, x_2, y_2)\f$,
/// where \f$(x_1,y_1)\f$ and \f$(x_2, y_2)\f$ are the ending points of each detected line segment.</param>
/// <param name="docs">Vector of Documents. Each doc is represented by a 8-elements vector \f$(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4)\f$,
/// where \f$(x_1,y_1)\f$, \f$(x_2, y_2)\f$, \f$(x_3, y_3)\f$ and \f$(x_4, y_4)\f$ are the corner of each detected Document.</param>
void LinesToDocs(const std::vector<cv::Vec4i> &lines, std::vector<cv::Vec8i> &docs);

//******************************
//********** Drawings **********
//******************************
/// <summary>
/// Draws the lines.
/// </summary>
/// <param name="src">The source.</param>
/// <param name="dst">The destination.</param>
/// <param name="lines">The lines.</param>
void DrawLines(const cv::Mat &src, cv::Mat &dst, const std::vector<cv::Vec4i> &lines);

/// <summary>
/// Draws the document shape.
/// </summary>
/// <param name="src">tri-channel 8-bit input image.</param>
/// <param name="dst">tri-channel 8-bit output image.</param>
/// <param name="docs">Vector of Documents. Each doc is represented by a 8-elements vector \f$(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4)\f$,
/// where \f$(x_1,y_1)\f$, \f$(x_2, y_2)\f$, \f$(x_3, y_3)\f$ and \f$(x_4, y_4)\f$ are the corner of each detected Document.</param>
void DrawDocShape(const cv::Mat &src, cv::Mat &dst, const std::vector<cv::Vec8i> &docs);