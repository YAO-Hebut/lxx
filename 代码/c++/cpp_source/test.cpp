#include<iostream>
#include<cmath>
using namespace std;
class Point_1D

{
protected:

	float x;//1D 点的x坐标

public:


	Point_1D(float a) {
		x = a;
	}
	float distance(const Point_1D& p1, const Point_1D& p2) {
		float d = 0.0;
		float t = 0.0;
		t = (p1.x - p2.x)* (p1.x - p2.x);

		d = sqrt(t);
		return d;
	}

};
class Point_2D :public  Point_1D {
protected:
	float y;//2D平面上点的y坐标
public:

	Point_2D(float a, float b) :Point_1D(a) {
		y = b;
	}
	float distance1(const Point_2D& p3, const Point_2D& p4) {
		float d = 0.0;
		float t = 0.0;
		t = (p3.x - p4.x) * (p3.x - p4.x) + (p3.y - p4.y) * (p3.y - p4.y);

		d = sqrt(t);
		return d;
	}
};
class Point_3D :public  Point_2D {
protected:
	float z;//3D立体空间中点的z坐标
public:
	Point_3D(float a, float b, float c) :Point_2D(a, b) {
		z = c;
	}
	float distance2(const Point_3D& p5, const Point_3D& p6) {
		float d = 0.0;
		float t = 0.0;
		t = (p5.x - p6.x) * (p5.x - p6.x) + (p5.y- p6.y) * (p5.y - p6.y)+(p5.z - p6.z) * (p5.z - p6.z);
		d = sqrt(t);
		return d;
	}
};
int main() {
	int ch = 0;

	while (cin >> ch) {
		if (ch == 0)break;
		if (ch == 1) {
			float a,b;
			cin >> a>>b;
			Point_1D p1(a);
			Point_1D p2(b);
			
			cout << "Distance from Point " << a << " to Point "<<b<<" is " << p1.distance(p1,p2) << endl;
		}
		else if (ch == 2) {
			float a, b,c,d;
			cin >> a >> b>>c>>d;
			Point_2D p2(a, b);
			Point_2D p3(c, d);
			cout << "Distance from Point" << "(" << a << "," << b << ")" << " to Point("<<c<<","<<d<<") is " << p2.distance1(p2,p3) << endl;

		}
		else if (ch == 3) {
			float a, b, c,d,e,f;
			cin >> a >> b >> c>>d>>e>>f;
			Point_3D p3(a, b, c);
			Point_3D p4(d, e, f);
			cout << "Distance from Point" << "(" << a << "," << b << "," << c << ")" << " to Point("<<d<<","<<e<<","<<f<<") is " << p3.distance2(p3,p4) << endl;
		}
	}
	return 0;
}
