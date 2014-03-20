#include <opencv2/opencv.hpp>
#include <map>
#include "LLPack/utils/extio.hpp"

using namespace cv;

void TopPixelValues(const Mat& src, int n) {
  if (src.channels() != 1) {
    Error("TopPixelValues only accepts single-channel image, "
	  "but src.channels() = %d", src.channels());
  }
  std::map<uchar, int> counter;
  for (int y = 0; y < src.rows; ++y) {
    for (int x = 0; x < src.cols; ++x) {
      uchar value = src.at<uchar>(y, x);
      ++counter[value];
    }
  }
  
  for (auto& pair : counter) {
    printf("%hhu:\t%d\n", pair.first, pair.second);
    --n;
    if (0 == n) return;
  }
}

Mat MorphCanny(Mat src) {
  Mat dst;
  Canny(src, dst, 50, 200, 3);
  return dst;
}

int main(int argc, char** argv) {
  Mat original = imread(argv[1]);
  if (!original.data) {
    Error("original image fail to load.");
    exit(-1);
  }
  Mat canny = MorphCanny(original);
  imshow("canny", canny);
  waitKey(0);
  return 0;
}
