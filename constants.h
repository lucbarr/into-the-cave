#pragma once

const int SQUARE_SIZE = 3;
const int PIXELS_TILE_SIZE = 24;

struct Vec2 {
  int x, y;
  Vec2() = default;
  Vec2(int a, int b): x(a), y(b) {}
  int operator * (Vec2 vec) const { // Dot product
    return (x*vec.x + y*vec.y);
  }
  bool operator==(Vec2 vec) const {
    return (x==vec.x && y==vec.y);
  }
  float dist2(Vec2 vec) const {
    return ((x-vec.x)*(x-vec.x)+(y-vec.y)*(y-vec.y));
  }
  Vec2 operator + (Vec2 vec) const {
    return Vec2(x+vec.x, y+vec.y);
  }
  Vec2 operator - (Vec2 vec) const {
    return Vec2(x-vec.x, y-vec.y);
  }

};
