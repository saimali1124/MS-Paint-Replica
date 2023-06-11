#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
float areaofTriangle(int, int, int, int, int, int);
class shape {
public:
	static int totalShapes;
	shape()
	{
		totalShapes++;
	}
	virtual void draw(sf::RenderWindow& win)
	{

	}


	virtual void paint(int color, sf::RenderWindow& win)
	{
	}
	virtual void erase(sf::RenderWindow& win)
	{

	}


};
int shape::totalShapes = 0;

class Circle :public shape
{
	sf::CircleShape C;
	float radius;
	int x;
	int y;

public:

	Circle(float r, int a, int b)
	{

		radius = r;
		x = a;
		y = b;
	}
	void draw(sf::RenderWindow& win)
	{
		C.setRadius(radius);
		C.setOutlineThickness(3);
		C.setOutlineColor(sf::Color::Black);
		C.setPosition(x, y);
		C.setOrigin(radius, radius);


		win.draw(C);


	}
	void paint(int color, sf::RenderWindow& win)
	{
		sf::Vertex pixel;
		sf::VertexArray shade;
		if (color == 0)
		{
			pixel.color = sf::Color::White;

		}
		if (color == 1)
		{
			pixel.color = sf::Color::Black;

		}

		if (color == 2)
		{
			pixel.color = sf::Color::Red;

		}
		if (color == 3)
		{

			pixel.color = sf::Color::Blue;

		}
		if (color == 4)
		{
			pixel.color = sf::Color::Green;

		}
		if (color == 5)
		{
			pixel.color = sf::Color::Yellow;

		}
		if (color == 6)
		{

			pixel.color = sf::Color::Magenta;
		}
		if (color == 7)
		{
			pixel.color = sf::Color::Cyan;
		}
		if (color == 8)
		{

			pixel.color = sf::Color::Color(192, 192, 192);

		}
		for (int i = 0; i < 1500; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				pixel.position = sf::Vector2f(i, j);
				if ((radius * radius) > ((i - x) * (i - x)) + ((j - y) * (j - y)))
				{
					shade.append(pixel);
				}

			}
		}
		win.draw(shade);

	}


	void erase(sf::RenderWindow& win)
	{
		radius = 0;
		C.setOutlineThickness(0);

	}


};

class Line :public shape {

	sf::Vertex line[2] =
	{
		sf::Vertex((sf::Vector2f(0.f, 0.f)),sf::Color::Black),
		sf::Vertex((sf::Vector2f(0.f, 0.f)),sf::Color::Black)
	};
	int x1, y1, x2, y2;

public:
	Line(int x, int y, int a, int b)
	{

		x1 = x;
		y1 = y;
		x2 = a;
		y2 = b;

		line[0].position = sf::Vector2f(x1, y1);
		line[1].position = sf::Vector2f(x2, y2);

	}

	void draw(sf::RenderWindow& win)
	{
		win.draw(line, 2, sf::Lines);
	}

	void erase(sf::RenderWindow& win)
	{
		x2 = x1;
		y2 = y1; //both points will be same hence no line

		//or line[1].position=sf::Vector2f(x1,y1);
	}
	void paint(int color, sf::RenderWindow& win)
	{
		if (color == 0)
		{
			line[0].color = sf::Color::White;
			line[1].color = sf::Color::White;

		}
		if (color == 1)
		{
			line[0].color = sf::Color::Black;
			line[1].color = sf::Color::Black;

		}

		if (color == 2)
		{

			line[0].color = sf::Color::Red;
			line[1].color = sf::Color::Red;

		}
		if (color == 3)
		{

			line[0].color = sf::Color::Blue;
			line[1].color = sf::Color::Blue;

		}
		if (color == 4)
		{

			line[0].color = sf::Color::Green;
			line[1].color = sf::Color::Green;

		}
		if (color == 5)
		{

			line[0].color = sf::Color::Yellow;
			line[1].color = sf::Color::Yellow;

		}
		if (color == 6)
		{

			line[0].color = sf::Color::Magenta;
			line[1].color = sf::Color::Magenta;

		}
		if (color == 7)
		{

			line[0].color = sf::Color::Cyan;
			line[1].color = sf::Color::Cyan;

		}
		if (color == 8)
		{

			line[0].color = sf::Color::Color(192, 192, 192);
			line[1].color = sf::Color::Color(192, 192, 192);

		}
	}

};

class Triangle :public shape
{
	int x1, y1, x2, y2, x3, y3;
	sf::Vertex line1[2];
	sf::Vertex line2[2];
	sf::Vertex line3[2];


public:
	Triangle(int a, int b, int c, int d, int e, int f)
	{

		x1 = a; x2 = c; x3 = e;
		y1 = b; y2 = d; y3 = f;
		line1[0].position = sf::Vector2f(a, b);
		line1[1].position = sf::Vector2f(c, d);
		line2[0].position = sf::Vector2f(c, d);
		line2[1].position = sf::Vector2f(e, f);
		line3[0].position = sf::Vector2f(e, f);
		line3[1].position = sf::Vector2f(a, b);

		line1[0].color = sf::Color::Black;
		line1[1].color = sf::Color::Black;
		line2[0].color = sf::Color::Black;
		line2[1].color = sf::Color::Black;
		line3[0].color = sf::Color::Black;
		line3[1].color = sf::Color::Black;

	}

	void draw(sf::RenderWindow& win)
	{
		win.draw(line1, 2, sf::Lines);
		win.draw(line2, 2, sf::Lines);
		win.draw(line3, 2, sf::Lines);
	}

	void erase(sf::RenderWindow& win)
	{
		cout << "Triangle erased" << endl;
		line1[0].position = sf::Vector2f(x1, y1);
		line1[1].position = sf::Vector2f(x2, y2);
		line2[0].position = sf::Vector2f(x2, y2);
		line2[1].position = sf::Vector2f(x3, y3);
		line3[0].position = sf::Vector2f(x3, y3);
		line3[1].position = sf::Vector2f(x1, y1);

		line1[0].color = sf::Color::White;
		line1[1].color = sf::Color::White;
		line2[0].color = sf::Color::White;
		line2[1].color = sf::Color::White;
		line3[0].color = sf::Color::White;
		line3[1].color = sf::Color::White;

		sf::Vertex pixel;
		sf::VertexArray shade;

		pixel.color = sf::Color::White;
		for (int i = 0; i < 1500; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				pixel.position = sf::Vector2f(i, j);
				float tri = areaofTriangle(x1, y1, x2, y2, x3, y3);
				float a = areaofTriangle(i, j, x2, y2, x3, y3);
				float b = areaofTriangle(x1, y1, i, j, x3, y3);
				float c = areaofTriangle(x1, y1, x2, y2, i, j);
				if (tri == a + b + c)
				{
					shade.append(pixel);
				}
			}
		}
		win.draw(shade);
	}

	void paint(int color, sf::RenderWindow& win)
	{
		sf::Vertex pixel;
		sf::VertexArray shade;
		if (color == 0)
		{
			pixel.color = sf::Color::White;

		}
		if (color == 1)
		{
			pixel.color = sf::Color::Black;

		}

		if (color == 2)
		{
			pixel.color = sf::Color::Red;

		}
		if (color == 3)
		{

			pixel.color = sf::Color::Blue;

		}
		if (color == 4)
		{
			pixel.color = sf::Color::Green;

		}
		if (color == 5)
		{
			pixel.color = sf::Color::Yellow;

		}
		if (color == 6)
		{

			pixel.color = sf::Color::Magenta;
		}
		if (color == 7)
		{
			pixel.color = sf::Color::Cyan;
		}
		if (color == 8)
		{

			pixel.color = sf::Color::Color(192, 192, 192);

		}
		for (int i = 0; i < 1500; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				pixel.position = sf::Vector2f(i, j);
				float tri = areaofTriangle(x1, y1, x2, y2, x3, y3);
				float a = areaofTriangle(i, j, x2, y2, x3, y3);
				float b = areaofTriangle(x1, y1, i, j, x3, y3);
				float c = areaofTriangle(x1, y1, x2, y2, i, j);
				if (tri == a + b + c)
				{
					shade.append(pixel);
				}
			}
		}
		win.draw(shade);
	}

};

class Rectangle :public shape {
	int x1, x2, y1, y2;
	sf::Vertex line1[2];
	sf::Vertex line2[2];
	sf::Vertex line3[2];
	sf::Vertex line4[2];
public:
	Rectangle(int a, int b, int c, int d) {

		x1 = a; y1 = b; x2 = c; y2 = d;

		line1[0].position = sf::Vector2f(a, b);
		line1[1].position = sf::Vector2f(a, d);
		line2[0].position = sf::Vector2f(a, d);
		line2[1].position = sf::Vector2f(c, d);
		line3[0].position = sf::Vector2f(c, d);
		line3[1].position = sf::Vector2f(c, b);
		line4[0].position = sf::Vector2f(c, b);
		line4[1].position = sf::Vector2f(a, b);

		line1[0].color = sf::Color::Black;
		line1[1].color = sf::Color::Black;
		line2[0].color = sf::Color::Black;
		line2[1].color = sf::Color::Black;
		line3[0].color = sf::Color::Black;
		line3[1].color = sf::Color::Black;
		line4[0].color = sf::Color::Black;
		line4[1].color = sf::Color::Black;


	}
	void draw(sf::RenderWindow& win)
	{
		win.draw(line1, 2, sf::Lines);
		win.draw(line2, 2, sf::Lines);
		win.draw(line3, 2, sf::Lines);
		win.draw(line4, 2, sf::Lines);
	}

	void erase(sf::RenderWindow& win)
	{
		line1[0].position = sf::Vector2f(x1, y1);
		line1[1].position = sf::Vector2f(x1, y1);
		line2[0].position = sf::Vector2f(x1, y1);
		line2[1].position = sf::Vector2f(x1, y1);
		line3[0].position = sf::Vector2f(x1, y1);
		line3[1].position = sf::Vector2f(x1, y1);
		line4[0].position = sf::Vector2f(x1, y1);
		line4[1].position = sf::Vector2f(x1, y1);

		sf::Vertex pixel;
		sf::VertexArray rec;
		for (int i = 1; i < y2 - y1; i++)
		{
			for (int j = 0; j < x2 - x1 - 1; j++)
			{
				pixel.color = sf::Color::White;

				pixel.position = sf::Vector2f(x1 + j, y1 + i);
				rec.append(pixel);
			}
		}
		win.draw(rec);
	}

	void paint(int color, sf::RenderWindow& win)
	{
		sf::Vertex pixel;
		sf::VertexArray rec;
		for (int i = 1; i < y2 - y1; i++)
		{
			for (int j = 0; j < x2 - x1 - 1; j++)
			{
				if (color == 0)
				{
					pixel.color = sf::Color::White;

				}
				if (color == 1)
				{
					pixel.color = sf::Color::Black;

				}

				if (color == 2)
				{
					pixel.color = sf::Color::Red;

				}
				if (color == 3)
				{

					pixel.color = sf::Color::Blue;

				}
				if (color == 4)
				{
					pixel.color = sf::Color::Green;

				}
				if (color == 5)
				{
					pixel.color = sf::Color::Yellow;

				}
				if (color == 6)
				{

					pixel.color = sf::Color::Magenta;
				}
				if (color == 7)
				{
					pixel.color = sf::Color::Cyan;
				}
				if (color == 8)
				{

					pixel.color = sf::Color::Color(192, 192, 192);

				}

				pixel.position = sf::Vector2f(x1 + j, y1 + i);
				rec.append(pixel);
			}
		}
		win.draw(rec);
	}

};



int main()
{

	shape* Shapes[4];
	int clickCount = 0, lineClick = 0, triangleClick = 0, rectangleClick = 0; int x1 = 0, x2 = 0, y1 = 0, y2 = 0, lx1 = 0, lx2 = 0, ly1 = 0, ly2 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0; int color = 0;  bool eraserSelected = false;
	float radius = 0;
	bool circleSelected = false, bucketSelected = false, lineSelected = false; bool circleClicked = false; bool triangleSelected = false; bool rectangleSelected = false;
	bool triangleClicked = false;
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Paint Application", sf::Style::Close);
	window.setKeyRepeatEnabled(false);




	sf::RectangleShape black(sf::Vector2f(30.0f, 30.0f));
	black.setFillColor(sf::Color::Black);
	sf::RectangleShape red(sf::Vector2f(30.0f, 30.0f));
	red.setFillColor(sf::Color::Red);
	red.setPosition(30, 0);
	sf::RectangleShape blue(sf::Vector2f(30.0f, 30.0f));
	blue.setFillColor(sf::Color::Blue);
	blue.setPosition(0, 30);
	sf::RectangleShape green(sf::Vector2f(30.0f, 30.0f));
	green.setFillColor(sf::Color::Green);
	green.setPosition(30, 30);
	sf::RectangleShape yellow(sf::Vector2f(30.0f, 30.0f));
	yellow.setFillColor(sf::Color::Yellow);
	yellow.setPosition(0, 60);
	sf::RectangleShape magenta(sf::Vector2f(30.0f, 30.0f));
	magenta.setFillColor(sf::Color::Magenta);
	magenta.setPosition(30, 60);
	sf::RectangleShape cyan(sf::Vector2f(30.0f, 30.0f));
	cyan.setFillColor(sf::Color::Cyan);
	cyan.setPosition(0, 90);
	sf::RectangleShape unique(sf::Vector2f(30.0f, 30.0f));
	unique.setFillColor(sf::Color::Color(192, 192, 192));
	unique.setPosition(30, 90);

	sf::RectangleShape CircleBOX(sf::Vector2f(30.0f, 30.0f));
	CircleBOX.setPosition(15, 140);
	CircleBOX.setOutlineThickness(2);


	sf::RectangleShape TriangleBOX(sf::Vector2f(30.0f, 30.0f));
	TriangleBOX.setPosition(15, 180);
	TriangleBOX.setOutlineThickness(2);

	sf::RectangleShape LineBOX(sf::Vector2f(30.0f, 30.0f));
	LineBOX.setPosition(15, 220);
	LineBOX.setOutlineThickness(2);


	sf::RectangleShape QuadBOX(sf::Vector2f(30.0f, 30.0f));
	QuadBOX.setPosition(15, 260);
	QuadBOX.setOutlineThickness(2);

	sf::RectangleShape RubberBOX(sf::Vector2f(30.0f, 30.0f));
	RubberBOX.setPosition(15, 300);
	RubberBOX.setOutlineThickness(2);

	sf::RectangleShape BucketBOX(sf::Vector2f(30.0f, 30.0f));
	BucketBOX.setPosition(15, 340);
	BucketBOX.setOutlineThickness(2);

	sf::Texture circle;
	circle.loadFromFile("dry-clean.png");
	CircleBOX.setTexture(&circle);


	sf::Texture triangle;
	triangle.loadFromFile("bleach.png");
	TriangleBOX.setTexture(&triangle);

	sf::Texture line;
	line.loadFromFile("diagonal-line.png");
	LineBOX.setTexture(&line);

	sf::Texture quad;
	quad.loadFromFile("quad.png");
	QuadBOX.setTexture(&quad);

	sf::Texture rubber;
	rubber.loadFromFile("rubber.png");
	RubberBOX.setTexture(&rubber);

	sf::Texture bucket;
	bucket.loadFromFile("bucket.png");
	BucketBOX.setTexture(&bucket);






	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:




				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 140 && event.mouseButton.y <= 170)
				{

					CircleBOX.setOutlineColor(sf::Color::Black);
					LineBOX.setOutlineColor(sf::Color::White);
					TriangleBOX.setOutlineColor(sf::Color::White);
					QuadBOX.setOutlineColor(sf::Color::White);
					RubberBOX.setOutlineColor(sf::Color::White);
					BucketBOX.setOutlineColor(sf::Color::White);
					circleSelected = true;
					eraserSelected = false;
					lineSelected = false;
					clickCount = 0;
					shape::totalShapes++;
					break;


				}

				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 180 && event.mouseButton.y <= 210)
				{
					TriangleBOX.setOutlineColor(sf::Color::Black);

					CircleBOX.setOutlineColor(sf::Color::White);
					LineBOX.setOutlineColor(sf::Color::White);
					QuadBOX.setOutlineColor(sf::Color::White);
					RubberBOX.setOutlineColor(sf::Color::White);
					BucketBOX.setOutlineColor(sf::Color::White);
					triangleSelected = true;
					triangleClick = 0;
					shape::totalShapes++;
					break;

				}
				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 220 && event.mouseButton.y <= 250)
				{

					LineBOX.setOutlineColor(sf::Color::Black);

					TriangleBOX.setOutlineColor(sf::Color::White);
					CircleBOX.setOutlineColor(sf::Color::White);
					QuadBOX.setOutlineColor(sf::Color::White);
					RubberBOX.setOutlineColor(sf::Color::White);
					BucketBOX.setOutlineColor(sf::Color::White);

					lineSelected = true;
					circleSelected = false;
					eraserSelected = false;
					circleClicked = false;



					shape::totalShapes++;

					break;
				}


				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 260 && event.mouseButton.y <= 290)
				{

					QuadBOX.setOutlineColor(sf::Color::Black);

					LineBOX.setOutlineColor(sf::Color::White);
					TriangleBOX.setOutlineColor(sf::Color::White);
					CircleBOX.setOutlineColor(sf::Color::White);
					RubberBOX.setOutlineColor(sf::Color::White);
					BucketBOX.setOutlineColor(sf::Color::White);
					rectangleSelected = true;


					shape::totalShapes++;
					break;
				}

				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 300 && event.mouseButton.y <= 330)
				{

					RubberBOX.setOutlineColor(sf::Color::Black);

					LineBOX.setOutlineColor(sf::Color::White);
					TriangleBOX.setOutlineColor(sf::Color::White);
					CircleBOX.setOutlineColor(sf::Color::White);
					QuadBOX.setOutlineColor(sf::Color::White);
					BucketBOX.setOutlineColor(sf::Color::White);
					eraserSelected = true;

					//bucketSelected = false;
					//circleClicked = false;

				}

				if (event.mouseButton.x > 15 && event.mouseButton.x <= 45 && event.mouseButton.y > 340 && event.mouseButton.y <= 370)
				{

					BucketBOX.setOutlineColor(sf::Color::Black);

					LineBOX.setOutlineColor(sf::Color::White);
					TriangleBOX.setOutlineColor(sf::Color::White);
					CircleBOX.setOutlineColor(sf::Color::White);
					QuadBOX.setOutlineColor(sf::Color::White);
					RubberBOX.setOutlineColor(sf::Color::White);
					bucketSelected = true;
					eraserSelected = false;
					circleClicked = false;

				}


				if (sf::Event::MouseButtonPressed && lineSelected == true && lineClick < 2)
				{

					if (lineClick == 0) {
						lx1 = event.mouseButton.x;
						ly1 = event.mouseButton.y;

					}
					if (lineClick == 1) {
						lx2 = event.mouseButton.x;
						ly2 = event.mouseButton.y;

					}
					lineClick++;
					cout << lineClick;
				}




				if (sf::Event::MouseButtonPressed && circleSelected == true && clickCount < 2)
				{

					if (clickCount == 0) {
						x1 = event.mouseButton.x;
						y1 = event.mouseButton.y;

					}
					if (clickCount == 1) {
						x2 = event.mouseButton.x;
						y2 = event.mouseButton.y;
						radius = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
					}
					clickCount++;
					cout << clickCount;
				}

				if ((radius * radius) > ((event.mouseButton.x - x1) * (event.mouseButton.x - x1)) + ((event.mouseButton.y - y1) * (event.mouseButton.y - y1)))
				{
					cout << "Circle clicked";
					circleClicked = true;

				}





				if (bucketSelected == true)
				{
					if (event.mouseButton.x > 0 && event.mouseButton.x <= 30 && event.mouseButton.y > 0 && event.mouseButton.y <= 30)
					{
						color = 1;
						cout << "black box clicked";
					}
					if (event.mouseButton.x > 30 && event.mouseButton.x <= 60 && event.mouseButton.y > 0 && event.mouseButton.y <= 30)
					{
						color = 2;
						cout << "red box clicked";
					}
					if (event.mouseButton.x > 0 && event.mouseButton.x <= 30 && event.mouseButton.y > 30 && event.mouseButton.y <= 60)
					{
						color = 3;
						cout << "blue box clicked";
					}
					if (event.mouseButton.x > 30 && event.mouseButton.x <= 60 && event.mouseButton.y > 30 && event.mouseButton.y <= 60)
					{
						color = 4;
						cout << "green box clicked";
					}
					if (event.mouseButton.x > 0 && event.mouseButton.x <= 30 && event.mouseButton.y > 60 && event.mouseButton.y <= 90)
					{
						color = 5;
						cout << "yellow box clicked";
					}
					if (event.mouseButton.x > 30 && event.mouseButton.x <= 60 && event.mouseButton.y > 60 && event.mouseButton.y <= 90)
					{
						color = 6;
						cout << "pink box clicked";
					}
					if (event.mouseButton.x > 0 && event.mouseButton.x <= 30 && event.mouseButton.y > 90 && event.mouseButton.y <= 120)
					{
						color = 7;
						cout << "skyblue box clicked";
					}
					if (event.mouseButton.x > 30 && event.mouseButton.x <= 60 && event.mouseButton.y > 90 && event.mouseButton.y <= 120)
					{
						color = 8;
						cout << "grey box clicked";
					}
				}

				if (sf::Event::MouseButtonPressed && triangleSelected == true && triangleClick < 3)
				{
					if (triangleClick == 0) {
						t1 = event.mouseButton.x;
						t2 = event.mouseButton.y;

					}
					if (triangleClick == 1) {
						t3 = event.mouseButton.x;
						t4 = event.mouseButton.y;

					}
					if (triangleClick == 2) {
						t5 = event.mouseButton.x;
						t6 = event.mouseButton.y;

					}
					triangleClick++;
					cout << triangleClick;
				}

				if (sf::Event::MouseButtonPressed && triangleClick >= 3) {
					float tri = areaofTriangle(t1, t2, t3, t4, t5, t6);
					float a = areaofTriangle(event.mouseButton.x, event.mouseButton.y, t3, t4, t5, t6);
					float b = areaofTriangle(t1, t2, event.mouseButton.x, event.mouseButton.y, t5, t6);
					float c = areaofTriangle(t1, t2, t3, t4, event.mouseButton.x, event.mouseButton.y);
					if (tri == a + b + c)
					{
						triangleClicked = true;
						cout << "triangleClicked";
					}
					cout << tri << "   " << a + b + c << endl;
				}



				if (sf::Event::MouseButtonPressed && rectangleSelected == true && rectangleClick < 2)
				{
					if (rectangleClick == 0) {
						r1 = event.mouseButton.x;
						r2 = event.mouseButton.y;

					}
					if (rectangleClick == 1) {
						r3 = event.mouseButton.x;
						r4 = event.mouseButton.y;

					}

					rectangleClick++;


				}

					if (eraserSelected == true)
					{
						if (sf::Event::MouseButtonPressed) {
							if (circleClicked == true) {

								Shapes[0]->erase(window);
								circleClicked = false;
								circleSelected = false;
								clickCount = 0;
								eraserSelected = false;
							}

							if (triangleClicked == true) {

								Shapes[2]->erase(window);
								triangleClicked = false;
								triangleSelected = false;
								triangleClick = 0;
								eraserSelected = false;
							}
							if (rectangleSelected == true) {

								Shapes[3]->erase(window);
								rectangleSelected = false;
								rectangleClick = 0;
								eraserSelected = false;
							}

							if (lineSelected == true) {

								Shapes[1]->erase(window);
								lineSelected = false;
								lineClick = 0;
								eraserSelected = false;
							}

						}
					}
				break;
			}




			window.clear(sf::Color::White);

			window.draw(black);

			window.draw(red);
			window.draw(green);
			window.draw(blue);
			window.draw(magenta);
			window.draw(cyan);
			window.draw(unique);
			window.draw(yellow);
			window.draw(CircleBOX);
			window.draw(TriangleBOX);
			window.draw(LineBOX);
			window.draw(QuadBOX);
			window.draw(RubberBOX);
			window.draw(BucketBOX);

			

			int r = 0, t = 0, l = 0, c = 0;

			if (rectangleClick == 2)
			{
				Shapes[3] = new Rectangle(r1, r2, r3, r4);
				Shapes[3]->draw(window);
				Shapes[3]->paint(0, window);
				r = 1;
			}

			if (triangleClick == 3)
			{
				Shapes[2] = new Triangle(t1, t2, t3, t4, t5, t6);
				Shapes[2]->draw(window);
				t = 1;
			}


			if (lineClick == 2) 
			{
				Shapes[1] = new Line(lx1, ly1, lx2, ly2);
				Shapes[1]->draw(window);
				l = 1;
			}

			if (clickCount == 2)
			{
				Shapes[0] = new Circle(radius, x1, y1);
				Shapes[0]->draw(window);
				Shapes[0]->paint(0, window);
				c = 1;
			}

			if (bucketSelected == true)
			{
				if (sf::Event::MouseButtonPressed) {
					if (circleClicked == true && c==1) {

						Shapes[0]->paint(color,window);
					}

					if (triangleClicked == true && t==1) {

						Shapes[2]->paint(color, window);

					}
					
						if(rectangleSelected == true  && r==1)
						{
							Shapes[3]->paint(color, window);
						}
		
					if (lineSelected == true && l==1) {

						Shapes[1]->paint(color, window);
					}

				}
			}
			window.display();

		}

	}

	return 0;
}


float areaofTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}