// A simple C++ program to demonstrate run-time
// polymorphism
#include <chrono>
#include <iostream>
#include <memory>
using namespace std;

typedef std::chrono::high_resolution_clock Clock;

// To store dimensions of an image
class Dimension {
public:
	Dimension(int X_, int _Y)
	{
		mX = X_;
		mY = _Y;
	}

private:
	int mX, mY;
};

// Base class for all image types
class Image {
public:
	virtual void Draw() = 0;
	virtual Dimension GetDimensionInPixels() = 0;

protected:
	int dimensionX;
	int dimensionY;
};

// For Tiff Images
class TiffImage : public Image {
public:
	void Draw() {
        	   // cout << "TiffImage::Draw() called" << endl;

    }
	Dimension GetDimensionInPixels()
	{
		return Dimension(dimensionX, dimensionY);
	}
};

// There can be more derived classes like PngImage,
// BitmapImage, etc

// Driver code that calls virtual function
void test()
{
	// An image type
	Image* pImage = new TiffImage;
    //unique_ptr<TiffImage> pImage = make_unique<TiffImage>();      
    //shared_ptr<TiffImage> pImage = make_shared<TiffImage>();      

	// Store time before virtual function calls
	auto then = Clock::now();

	// Call Draw 1000 times to make sure performance
	// is visible
	for (int i = 0; i < 1000; ++i)
		pImage->Draw();

	// Store time after virtual function calls
	auto now = Clock::now();

	cout << "Time taken: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
		<< " nanoseconds" << endl;

}
