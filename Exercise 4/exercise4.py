#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import cv2

def main():
    src=cv2.imread('/Users/jiahaozhang/Downloads/OpenCV_homework/Test_images/coins.png')
    gray = cv2.cvtColor(src, cv2.COLOR_RGB2GRAY)
    cv2.namedWindow("Input image", cv2.WINDOW_AUTOSIZE)
    cv2.imshow("Input image", src)
    
    threshold_type = 2
    threshold_value = 128
    [retval, dst] = cv2.threshold(gray, threshold_value, 255, threshold_type)
    cv2.imshow("Thresholded Image", dst)
    
    current_threshold = 128
    max_threshold = 255
    
    [retval, thresholded] = cv2.threshold(gray, current_threshold, max_threshold, cv2.THRESH_BINARY)
    cv2.imshow("Binary threshold", thresholded)
    
    threshold1 = 27
    threshold2 = 125
    
    [retval, binary_image1] = cv2.threshold(gray, threshold1, max_threshold, cv2.THRESH_BINARY)
    [retval, binary_image2] = cv2.threshold(gray, threshold2, max_threshold, cv2.THRESH_BINARY_INV)
    band_thresholded_image = cv2.bitwise_and(binary_image1, binary_image2)
    cv2.imshow("Band Thresholding", band_thresholded_image)