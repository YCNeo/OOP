#include "gtest/gtest.h"
#include "sphere.h"

TEST(SphereTest, ConstructorTest) {
    Sphere sph(0, 1, 2, 3);
    EXPECT_EQ(sph.getOrigin()[0], 0);
    EXPECT_EQ(sph.getOrigin()[1], 1);
    EXPECT_EQ(sph.getOrigin()[2], 2);
    EXPECT_EQ(sph.getRadius(), 3);

	// Sphere sphDefault = new Sphere();
	Sphere sphNegative(0, 0, 0, -3);	
    EXPECT_FALSE(sphNegative.getRadius() == 3);
	EXPECT_TRUE(sph.getRadius() == 3);
	sphNegative.setOrigin(4, 4, 4);
	sphNegative.setRadius(9);
	EXPECT_FALSE(sph.intersect(sphNegative));
	EXPECT_LE(sph.Volume(), sph.SurfaceArea());

}	
