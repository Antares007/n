#pragma region std_includes
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <streambuf>
#include <string>
#include <thread>
#include <vector>
#pragma endregion

#pragma region compiler_config
#include <filesystem>
namespace _gfs = std::filesystem;
namespace X11 {
#include <X11/X.h>
#include <X11/Xlib.h>
} // namespace X11
#pragma endregion

#pragma region pge_declaration
namespace olc {
class PixelGameEngine;
class Sprite;

constexpr uint8_t nMouseButtons = 5;
constexpr uint8_t nDefaultAlpha = 0xFF;
constexpr uint32_t nDefaultPixel = (nDefaultAlpha << 24);
enum rcode { FAIL = 0, OK = 1, NO_FILE = -1 };

struct Pixel {
  union {
    uint32_t n = nDefaultPixel;
    struct {
      uint8_t r;
      uint8_t g;
      uint8_t b;
      uint8_t a;
    };
  };

  enum Mode { NORMAL, MASK, ALPHA, CUSTOM };

  Pixel();
  Pixel(uint8_t red, uint8_t green, uint8_t blue,
        uint8_t alpha = nDefaultAlpha);
  Pixel(uint32_t p);
  Pixel &operator=(const Pixel &v) = default;
  bool operator==(const Pixel &p) const;
  bool operator!=(const Pixel &p) const;
  Pixel operator*(const float i) const;
  Pixel operator/(const float i) const;
  Pixel &operator*=(const float i);
  Pixel &operator/=(const float i);
  Pixel operator+(const Pixel &p) const;
  Pixel operator-(const Pixel &p) const;
  Pixel &operator+=(const Pixel &p);
  Pixel &operator-=(const Pixel &p);
  Pixel inv() const;
};

Pixel PixelF(float red, float green, float blue, float alpha = 1.0f);
Pixel PixelLerp(const olc::Pixel &p1, const olc::Pixel &p2, float t);

static const Pixel GREY(192, 192, 192), DARK_GREY(128, 128, 128),
    VERY_DARK_GREY(64, 64, 64), RED(255, 0, 0), DARK_RED(128, 0, 0),
    VERY_DARK_RED(64, 0, 0), YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0),
    VERY_DARK_YELLOW(64, 64, 0), GREEN(0, 255, 0), DARK_GREEN(0, 128, 0),
    VERY_DARK_GREEN(0, 64, 0), CYAN(0, 255, 255), DARK_CYAN(0, 128, 128),
    VERY_DARK_CYAN(0, 64, 64), BLUE(0, 0, 255), DARK_BLUE(0, 0, 128),
    VERY_DARK_BLUE(0, 0, 64), MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128),
    VERY_DARK_MAGENTA(64, 0, 64), WHITE(255, 255, 255), BLACK(0, 0, 0),
    BLANK(0, 0, 0, 0);

enum Key {
  NONE,
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z,
  K0,
  K1,
  K2,
  K3,
  K4,
  K5,
  K6,
  K7,
  K8,
  K9,
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  F10,
  F11,
  F12,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  SPACE,
  TAB,
  SHIFT,
  CTRL,
  INS,
  DEL,
  HOME,
  END,
  PGUP,
  PGDN,
  BACK,
  ESCAPE,
  RETURN,
  ENTER,
  PAUSE,
  SCROLL,
  NP0,
  NP1,
  NP2,
  NP3,
  NP4,
  NP5,
  NP6,
  NP7,
  NP8,
  NP9,
  NP_MUL,
  NP_DIV,
  NP_ADD,
  NP_SUB,
  NP_DECIMAL,
  PERIOD,
  EQUALS,
  COMMA,
  MINUS,
  OEM_1,
  OEM_2,
  OEM_3,
  OEM_4,
  OEM_5,
  OEM_6,
  OEM_7,
  OEM_8,
  CAPS_LOCK,
  ENUM_END
};

struct HWButton {
  bool bPressed = false;
  bool bReleased = false;
  bool bHeld = false;
};

template <class T> struct v2d_generic {
  T x = 0;
  T y = 0;
  v2d_generic() : x(0), y(0) {}
  v2d_generic(T _x, T _y) : x(_x), y(_y) {}
  v2d_generic(const v2d_generic &v) : x(v.x), y(v.y) {}
  v2d_generic &operator=(const v2d_generic &v) = default;
  T mag() const { return T(std::sqrt(x * x + y * y)); }
  T mag2() const { return x * x + y * y; }
  v2d_generic norm() const {
    T r = 1 / mag();
    return v2d_generic(x * r, y * r);
  }
  v2d_generic perp() const { return v2d_generic(-y, x); }
  v2d_generic floor() const {
    return v2d_generic(std::floor(x), std::floor(y));
  }
  v2d_generic ceil() const { return v2d_generic(std::ceil(x), std::ceil(y)); }
  v2d_generic max(const v2d_generic &v) const {
    return v2d_generic(std::max(x, v.x), std::max(y, v.y));
  }
  v2d_generic min(const v2d_generic &v) const {
    return v2d_generic(std::min(x, v.x), std::min(y, v.y));
  }
  T dot(const v2d_generic &rhs) const {
    return this->x * rhs.x + this->y * rhs.y;
  }
  T cross(const v2d_generic &rhs) const {
    return this->x * rhs.y - this->y * rhs.x;
  }
  v2d_generic operator+(const v2d_generic &rhs) const {
    return v2d_generic(this->x + rhs.x, this->y + rhs.y);
  }
  v2d_generic operator-(const v2d_generic &rhs) const {
    return v2d_generic(this->x - rhs.x, this->y - rhs.y);
  }
  v2d_generic operator*(const T &rhs) const {
    return v2d_generic(this->x * rhs, this->y * rhs);
  }
  v2d_generic operator*(const v2d_generic &rhs) const {
    return v2d_generic(this->x * rhs.x, this->y * rhs.y);
  }
  v2d_generic operator/(const T &rhs) const {
    return v2d_generic(this->x / rhs, this->y / rhs);
  }
  v2d_generic operator/(const v2d_generic &rhs) const {
    return v2d_generic(this->x / rhs.x, this->y / rhs.y);
  }
  v2d_generic &operator+=(const v2d_generic &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }
  v2d_generic &operator-=(const v2d_generic &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
  }
  v2d_generic &operator*=(const T &rhs) {
    this->x *= rhs;
    this->y *= rhs;
    return *this;
  }
  v2d_generic &operator/=(const T &rhs) {
    this->x /= rhs;
    this->y /= rhs;
    return *this;
  }
  v2d_generic &operator*=(const v2d_generic &rhs) {
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
  }
  v2d_generic &operator/=(const v2d_generic &rhs) {
    this->x /= rhs.x;
    this->y /= rhs.y;
    return *this;
  }
  v2d_generic operator+() const { return {+x, +y}; }
  v2d_generic operator-() const { return {-x, -y}; }
  bool operator==(const v2d_generic &rhs) const {
    return (this->x == rhs.x && this->y == rhs.y);
  }
  bool operator!=(const v2d_generic &rhs) const {
    return (this->x != rhs.x || this->y != rhs.y);
  }
  const std::string str() const {
    return std::string("(") + std::to_string(this->x) + "," +
           std::to_string(this->y) + ")";
  }
  friend std::ostream &operator<<(std::ostream &os, const v2d_generic &rhs) {
    os << rhs.str();
    return os;
  }
  operator v2d_generic<int32_t>() const {
    return {static_cast<int32_t>(this->x), static_cast<int32_t>(this->y)};
  }
  operator v2d_generic<float>() const {
    return {static_cast<float>(this->x), static_cast<float>(this->y)};
  }
  operator v2d_generic<double>() const {
    return {static_cast<double>(this->x), static_cast<double>(this->y)};
  }
};

template <class T>
inline v2d_generic<T> operator*(const float &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs * (float)rhs.x), (T)(lhs * (float)rhs.y));
}
template <class T>
inline v2d_generic<T> operator*(const double &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs * (double)rhs.x), (T)(lhs * (double)rhs.y));
}
template <class T>
inline v2d_generic<T> operator*(const int &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs * (int)rhs.x), (T)(lhs * (int)rhs.y));
}
template <class T>
inline v2d_generic<T> operator/(const float &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs / (float)rhs.x), (T)(lhs / (float)rhs.y));
}
template <class T>
inline v2d_generic<T> operator/(const double &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs / (double)rhs.x), (T)(lhs / (double)rhs.y));
}
template <class T>
inline v2d_generic<T> operator/(const int &lhs, const v2d_generic<T> &rhs) {
  return v2d_generic<T>((T)(lhs / (int)rhs.x), (T)(lhs / (int)rhs.y));
}

template <class T, class U>
inline bool operator<(const v2d_generic<T> &lhs, const v2d_generic<U> &rhs) {
  return lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x);
}
template <class T, class U>
inline bool operator>(const v2d_generic<T> &lhs, const v2d_generic<U> &rhs) {
  return lhs.y > rhs.y || (lhs.y == rhs.y && lhs.x > rhs.x);
}

typedef v2d_generic<int32_t> vi2d;
typedef v2d_generic<uint32_t> vu2d;
typedef v2d_generic<float> vf2d;
typedef v2d_generic<double> vd2d;

struct ResourceBuffer : public std::streambuf {
  ResourceBuffer(std::ifstream &ifs, uint32_t offset, uint32_t size);
  std::vector<char> vMemory;
};

class ResourcePack : public std::streambuf {
public:
  ResourcePack();
  ~ResourcePack();
  bool AddFile(const std::string &sFile);
  bool LoadPack(const std::string &sFile, const std::string &sKey);
  bool SavePack(const std::string &sFile, const std::string &sKey);
  ResourceBuffer GetFileBuffer(const std::string &sFile);
  bool Loaded();

private:
  struct sResourceFile {
    uint32_t nSize;
    uint32_t nOffset;
  };
  std::map<std::string, sResourceFile> mapFiles;
  std::ifstream baseFile;
  std::vector<char> scramble(const std::vector<char> &data,
                             const std::string &key);
  std::string makeposix(const std::string &path);
};

class ImageLoader {
public:
  ImageLoader() = default;
  virtual ~ImageLoader() = default;
  virtual olc::rcode LoadImageResource(olc::Sprite *spr,
                                       const std::string &sImageFile,
                                       olc::ResourcePack *pack) = 0;
  virtual olc::rcode SaveImageResource(olc::Sprite *spr,
                                       const std::string &sImageFile) = 0;
};

class Sprite {
public:
  Sprite();
  Sprite(const std::string &sImageFile, olc::ResourcePack *pack = nullptr);
  Sprite(int32_t w, int32_t h);
  Sprite(const olc::Sprite &) = delete;
  ~Sprite();

public:
  olc::rcode LoadFromFile(const std::string &sImageFile,
                          olc::ResourcePack *pack = nullptr);
  olc::rcode LoadFromPGESprFile(const std::string &sImageFile,
                                olc::ResourcePack *pack = nullptr);
  olc::rcode SaveToPGESprFile(const std::string &sImageFile);

public:
  int32_t width = 0;
  int32_t height = 0;
  enum Mode { NORMAL, PERIODIC };
  enum Flip { NONE = 0, HORIZ = 1, VERT = 2 };

public:
  void SetSampleMode(olc::Sprite::Mode mode = olc::Sprite::Mode::NORMAL);
  Pixel GetPixel(int32_t x, int32_t y) const;
  bool SetPixel(int32_t x, int32_t y, Pixel p);
  Pixel GetPixel(const olc::vi2d &a) const;
  bool SetPixel(const olc::vi2d &a, Pixel p);
  Pixel Sample(float x, float y) const;
  Pixel SampleBL(float u, float v) const;
  Pixel *GetData();
  olc::Sprite *Duplicate();
  olc::Sprite *Duplicate(const olc::vi2d &vPos, const olc::vi2d &vSize);
  std::vector<olc::Pixel> pColData;
  Mode modeSample = Mode::NORMAL;

  static std::unique_ptr<olc::ImageLoader> loader;
};

class Decal {
public:
  Decal(olc::Sprite *spr, bool filter = false, bool clamp = true);
  Decal(const uint32_t nExistingTextureResource, olc::Sprite *spr);
  virtual ~Decal();
  void Update();
  void UpdateSprite();

public:
  int32_t id = -1;
  olc::Sprite *sprite = nullptr;
  olc::vf2d vUVScale = {1.0f, 1.0f};
};

enum class DecalMode {
  NORMAL,
  ADDITIVE,
  MULTIPLICATIVE,
  STENCIL,
  ILLUMINATE,
  WIREFRAME,
};

class Renderable {
public:
  Renderable() = default;
  olc::rcode Load(const std::string &sFile, ResourcePack *pack = nullptr,
                  bool filter = false, bool clamp = true);
  void Create(uint32_t width, uint32_t height, bool filter = false,
              bool clamp = true);
  olc::Decal *Decal() const;
  olc::Sprite *Sprite() const;

private:
  std::unique_ptr<olc::Sprite> pSprite = nullptr;
  std::unique_ptr<olc::Decal> pDecal = nullptr;
};

struct DecalInstance {
  olc::Decal *decal = nullptr;
  std::vector<olc::vf2d> pos;
  std::vector<olc::vf2d> uv;
  std::vector<float> w;
  std::vector<olc::Pixel> tint;
  olc::DecalMode mode = olc::DecalMode::NORMAL;
  uint32_t points = 0;
};

struct LayerDesc {
  olc::vf2d vOffset = {0, 0};
  olc::vf2d vScale = {1, 1};
  bool bShow = false;
  bool bUpdate = false;
  olc::Sprite *pDrawTarget = nullptr;
  uint32_t nResID = 0;
  std::vector<DecalInstance> vecDecalInstance;
  olc::Pixel tint = olc::WHITE;
  std::function<void()> funcHook = nullptr;
};

class Renderer {
public:
  virtual ~Renderer() = default;
  virtual void PrepareDevice() = 0;
  virtual olc::rcode CreateDevice(std::vector<void *> params, bool bFullScreen,
                                  bool bVSYNC) = 0;
  virtual olc::rcode DestroyDevice() = 0;
  virtual void DisplayFrame() = 0;
  virtual void PrepareDrawing() = 0;
  virtual void SetDecalMode(const olc::DecalMode &mode) = 0;
  virtual void DrawLayerQuad(const olc::vf2d &offset, const olc::vf2d &scale,
                             const olc::Pixel tint) = 0;
  virtual void DrawDecal(const olc::DecalInstance &decal) = 0;
  virtual uint32_t CreateTexture(const uint32_t width, const uint32_t height,
                                 const bool filtered = false,
                                 const bool clamp = true) = 0;
  virtual void UpdateTexture(uint32_t id, olc::Sprite *spr) = 0;
  virtual void ReadTexture(uint32_t id, olc::Sprite *spr) = 0;
  virtual uint32_t DeleteTexture(const uint32_t id) = 0;
  virtual void ApplyTexture(uint32_t id) = 0;
  virtual void UpdateViewport(const olc::vi2d &pos, const olc::vi2d &size) = 0;
  virtual void ClearBuffer(olc::Pixel p, bool bDepth) = 0;
  static olc::PixelGameEngine *ptrPGE;
};

class Platform {
public:
  virtual ~Platform() = default;
  virtual olc::rcode ApplicationStartUp() = 0;
  virtual olc::rcode ApplicationCleanUp() = 0;
  virtual olc::rcode ThreadStartUp() = 0;
  virtual olc::rcode ThreadCleanUp() = 0;
  virtual olc::rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC,
                                    const olc::vi2d &vViewPos,
                                    const olc::vi2d &vViewSize) = 0;
  virtual olc::rcode CreateWindowPane(const olc::vi2d &vWindowPos,
                                      olc::vi2d &vWindowSize,
                                      bool bFullScreen) = 0;
  virtual olc::rcode SetWindowTitle(const std::string &s) = 0;
  virtual olc::rcode StartSystemEventLoop() = 0;
  virtual olc::rcode HandleSystemEvent() = 0;
  static olc::PixelGameEngine *ptrPGE;
};

class PGEX;

static std::unique_ptr<Renderer> renderer;
static std::unique_ptr<Platform> platform;
static std::map<size_t, uint8_t> mapKeys;

class PixelGameEngine {
public:
  PixelGameEngine();
  virtual ~PixelGameEngine();

public:
  olc::rcode Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w,
                       int32_t pixel_h, bool full_screen = false,
                       bool vsync = false, bool cohesion = false);
  olc::rcode Start();

public:
  virtual bool OnUserCreate();

  virtual bool OnUserUpdate(float fElapsedTime);

  virtual bool OnUserDestroy();

public:
  bool IsFocused() const;

  HWButton GetKey(Key k) const;

  HWButton GetMouse(uint32_t b) const;

  int32_t GetMouseX() const;

  int32_t GetMouseY() const;

  int32_t GetMouseWheel() const;

  const olc::vi2d &GetWindowMouse() const;

  const olc::vi2d &GetMousePos() const;

public:
  int32_t ScreenWidth() const;

  int32_t ScreenHeight() const;

  int32_t GetDrawTargetWidth() const;

  int32_t GetDrawTargetHeight() const;

  olc::Sprite *GetDrawTarget() const;

  void SetScreenSize(int w, int h);

  void SetDrawTarget(Sprite *target);

  uint32_t GetFPS() const;

  float GetElapsedTime() const;

  const olc::vi2d &GetWindowSize() const;

  const olc::vi2d &GetPixelSize() const;

  const olc::vi2d &GetScreenPixelSize() const;

public:
  void SetDrawTarget(uint8_t layer);
  void EnableLayer(uint8_t layer, bool b);
  void SetLayerOffset(uint8_t layer, const olc::vf2d &offset);
  void SetLayerOffset(uint8_t layer, float x, float y);
  void SetLayerScale(uint8_t layer, const olc::vf2d &scale);
  void SetLayerScale(uint8_t layer, float x, float y);
  void SetLayerTint(uint8_t layer, const olc::Pixel &tint);
  void SetLayerCustomRenderFunction(uint8_t layer, std::function<void()> f);

  std::vector<LayerDesc> &GetLayers();
  uint32_t CreateLayer();

  void SetPixelMode(Pixel::Mode m);
  Pixel::Mode GetPixelMode();

  void SetPixelMode(std::function<olc::Pixel(const int x, const int y,
                                             const olc::Pixel &pSource,
                                             const olc::Pixel &pDest)>
                        pixelMode);

  void SetPixelBlend(float fBlend);

public:
  virtual bool Draw(int32_t x, int32_t y, Pixel p = olc::WHITE);
  bool Draw(const olc::vi2d &pos, Pixel p = olc::WHITE);

  void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                Pixel p = olc::WHITE, uint32_t pattern = 0xFFFFFFFF);
  void DrawLine(const olc::vi2d &pos1, const olc::vi2d &pos2,
                Pixel p = olc::WHITE, uint32_t pattern = 0xFFFFFFFF);

  void DrawCircle(int32_t x, int32_t y, int32_t radius, Pixel p = olc::WHITE,
                  uint8_t mask = 0xFF);
  void DrawCircle(const olc::vi2d &pos, int32_t radius, Pixel p = olc::WHITE,
                  uint8_t mask = 0xFF);

  void FillCircle(int32_t x, int32_t y, int32_t radius, Pixel p = olc::WHITE);
  void FillCircle(const olc::vi2d &pos, int32_t radius, Pixel p = olc::WHITE);

  void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h,
                Pixel p = olc::WHITE);
  void DrawRect(const olc::vi2d &pos, const olc::vi2d &size,
                Pixel p = olc::WHITE);

  void FillRect(int32_t x, int32_t y, int32_t w, int32_t h,
                Pixel p = olc::WHITE);
  void FillRect(const olc::vi2d &pos, const olc::vi2d &size,
                Pixel p = olc::WHITE);

  void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3,
                    int32_t y3, Pixel p = olc::WHITE);
  void DrawTriangle(const olc::vi2d &pos1, const olc::vi2d &pos2,
                    const olc::vi2d &pos3, Pixel p = olc::WHITE);

  void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3,
                    int32_t y3, Pixel p = olc::WHITE);
  void FillTriangle(const olc::vi2d &pos1, const olc::vi2d &pos2,
                    const olc::vi2d &pos3, Pixel p = olc::WHITE);

  void DrawSprite(int32_t x, int32_t y, Sprite *sprite, uint32_t scale = 1,
                  uint8_t flip = olc::Sprite::NONE);
  void DrawSprite(const olc::vi2d &pos, Sprite *sprite, uint32_t scale = 1,
                  uint8_t flip = olc::Sprite::NONE);

  void DrawPartialSprite(int32_t x, int32_t y, Sprite *sprite, int32_t ox,
                         int32_t oy, int32_t w, int32_t h, uint32_t scale = 1,
                         uint8_t flip = olc::Sprite::NONE);
  void DrawPartialSprite(const olc::vi2d &pos, Sprite *sprite,
                         const olc::vi2d &sourcepos, const olc::vi2d &size,
                         uint32_t scale = 1, uint8_t flip = olc::Sprite::NONE);

  void DrawString(int32_t x, int32_t y, const std::string &sText,
                  Pixel col = olc::WHITE, uint32_t scale = 1);
  void DrawString(const olc::vi2d &pos, const std::string &sText,
                  Pixel col = olc::WHITE, uint32_t scale = 1);
  olc::vi2d GetTextSize(const std::string &s);

  void DrawStringProp(int32_t x, int32_t y, const std::string &sText,
                      Pixel col = olc::WHITE, uint32_t scale = 1);
  void DrawStringProp(const olc::vi2d &pos, const std::string &sText,
                      Pixel col = olc::WHITE, uint32_t scale = 1);
  olc::vi2d GetTextSizeProp(const std::string &s);

  void SetDecalMode(const olc::DecalMode &mode);

  void DrawDecal(const olc::vf2d &pos, olc::Decal *decal,
                 const olc::vf2d &scale = {1.0f, 1.0f},
                 const olc::Pixel &tint = olc::WHITE);

  void DrawPartialDecal(const olc::vf2d &pos, olc::Decal *decal,
                        const olc::vf2d &source_pos,
                        const olc::vf2d &source_size,
                        const olc::vf2d &scale = {1.0f, 1.0f},
                        const olc::Pixel &tint = olc::WHITE);
  void DrawPartialDecal(const olc::vf2d &pos, const olc::vf2d &size,
                        olc::Decal *decal, const olc::vf2d &source_pos,
                        const olc::vf2d &source_size,
                        const olc::Pixel &tint = olc::WHITE);

  void DrawExplicitDecal(olc::Decal *decal, const olc::vf2d *pos,
                         const olc::vf2d *uv, const olc::Pixel *col,
                         uint32_t elements = 4);

  void DrawWarpedDecal(olc::Decal *decal, const olc::vf2d (&pos)[4],
                       const olc::Pixel &tint = olc::WHITE);
  void DrawWarpedDecal(olc::Decal *decal, const olc::vf2d *pos,
                       const olc::Pixel &tint = olc::WHITE);
  void DrawWarpedDecal(olc::Decal *decal, const std::array<olc::vf2d, 4> &pos,
                       const olc::Pixel &tint = olc::WHITE);

  void DrawPartialWarpedDecal(olc::Decal *decal, const olc::vf2d (&pos)[4],
                              const olc::vf2d &source_pos,
                              const olc::vf2d &source_size,
                              const olc::Pixel &tint = olc::WHITE);
  void DrawPartialWarpedDecal(olc::Decal *decal, const olc::vf2d *pos,
                              const olc::vf2d &source_pos,
                              const olc::vf2d &source_size,
                              const olc::Pixel &tint = olc::WHITE);
  void DrawPartialWarpedDecal(olc::Decal *decal,
                              const std::array<olc::vf2d, 4> &pos,
                              const olc::vf2d &source_pos,
                              const olc::vf2d &source_size,
                              const olc::Pixel &tint = olc::WHITE);

  void DrawRotatedDecal(const olc::vf2d &pos, olc::Decal *decal,
                        const float fAngle,
                        const olc::vf2d &center = {0.0f, 0.0f},
                        const olc::vf2d &scale = {1.0f, 1.0f},
                        const olc::Pixel &tint = olc::WHITE);
  void DrawPartialRotatedDecal(const olc::vf2d &pos, olc::Decal *decal,
                               const float fAngle, const olc::vf2d &center,
                               const olc::vf2d &source_pos,
                               const olc::vf2d &source_size,
                               const olc::vf2d &scale = {1.0f, 1.0f},
                               const olc::Pixel &tint = olc::WHITE);

  void DrawStringDecal(const olc::vf2d &pos, const std::string &sText,
                       const Pixel col = olc::WHITE,
                       const olc::vf2d &scale = {1.0f, 1.0f});
  void DrawStringPropDecal(const olc::vf2d &pos, const std::string &sText,
                           const Pixel col = olc::WHITE,
                           const olc::vf2d &scale = {1.0f, 1.0f});

  void FillRectDecal(const olc::vf2d &pos, const olc::vf2d &size,
                     const olc::Pixel col = olc::WHITE);

  void GradientFillRectDecal(const olc::vf2d &pos, const olc::vf2d &size,
                             const olc::Pixel colTL, const olc::Pixel colBL,
                             const olc::Pixel colBR, const olc::Pixel colTR);

  void DrawPolygonDecal(olc::Decal *decal, const std::vector<olc::vf2d> &pos,
                        const std::vector<olc::vf2d> &uv,
                        const olc::Pixel tint = olc::WHITE);

  void Clear(Pixel p);

  void ClearBuffer(Pixel p, bool bDepth = true);

  olc::Sprite *GetFontSprite();

public:
  std::string sAppName;

private:
  Sprite *pDrawTarget = nullptr;
  Pixel::Mode nPixelMode = Pixel::NORMAL;
  float fBlendFactor = 1.0f;
  olc::vi2d vScreenSize = {256, 240};
  olc::vf2d vInvScreenSize = {1.0f / 256.0f, 1.0f / 240.0f};
  olc::vi2d vPixelSize = {4, 4};
  olc::vi2d vScreenPixelSize = {4, 4};
  olc::vi2d vMousePos = {0, 0};
  int32_t nMouseWheelDelta = 0;
  olc::vi2d vMousePosCache = {0, 0};
  olc::vi2d vMouseWindowPos = {0, 0};
  int32_t nMouseWheelDeltaCache = 0;
  olc::vi2d vWindowSize = {0, 0};
  olc::vi2d vViewPos = {0, 0};
  olc::vi2d vViewSize = {0, 0};
  bool bFullScreen = false;
  olc::vf2d vPixel = {1.0f, 1.0f};
  bool bHasInputFocus = false;
  bool bHasMouseFocus = false;
  bool bEnableVSYNC = false;
  float fFrameTimer = 1.0f;
  float fLastElapsed = 0.0f;
  int nFrameCount = 0;
  Sprite *fontSprite = nullptr;
  Decal *fontDecal = nullptr;
  Sprite *pDefaultDrawTarget = nullptr;
  std::vector<LayerDesc> vLayers;
  uint8_t nTargetLayer = 0;
  uint32_t nLastFPS = 0;
  bool bPixelCohesion = false;
  DecalMode nDecalMode = DecalMode::NORMAL;
  std::function<olc::Pixel(const int x, const int y, const olc::Pixel &,
                           const olc::Pixel &)>
      funcPixelMode;
  std::chrono::time_point<std::chrono::system_clock> m_tp1, m_tp2;
  std::vector<olc::vi2d> vFontSpacing;

  bool pKeyNewState[256] = {0};
  bool pKeyOldState[256] = {0};
  HWButton pKeyboardState[256] = {0};

  bool pMouseNewState[nMouseButtons] = {0};
  bool pMouseOldState[nMouseButtons] = {0};
  HWButton pMouseState[nMouseButtons] = {0};

  void EngineThread();

  static std::atomic<bool> bAtomActive;

public:
  void olc_UpdateMouse(int32_t x, int32_t y);
  void olc_UpdateMouseWheel(int32_t delta);
  void olc_UpdateWindowSize(int32_t x, int32_t y);
  void olc_UpdateViewport();
  void olc_ConstructFontSheet();
  void olc_CoreUpdate();
  void olc_PrepareEngine();
  void olc_UpdateMouseState(int32_t button, bool state);
  void olc_UpdateKeyState(int32_t key, bool state);
  void olc_UpdateMouseFocus(bool state);
  void olc_UpdateKeyFocus(bool state);
  void olc_Terminate();
  void olc_Reanimate();
  bool olc_IsRunning();

  virtual void olc_ConfigureSystem();

public:
  friend class PGEX;
  void pgex_Register(olc::PGEX *pgex);

private:
  std::vector<olc::PGEX *> vExtensions;
};

class PGEX {
  friend class olc::PixelGameEngine;

public:
  PGEX(bool bHook = false);

protected:
  virtual void OnBeforeUserCreate();
  virtual void OnAfterUserCreate();
  virtual void OnBeforeUserUpdate(float &fElapsedTime);
  virtual void OnAfterUserUpdate(float fElapsedTime);

protected:
  static PixelGameEngine *pge;
};
} // namespace olc

#pragma endregion
#pragma region pge_implementation
namespace olc {

Pixel::Pixel() {
  r = 0;
  g = 0;
  b = 0;
  a = nDefaultAlpha;
}

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
  n = red | (green << 8) | (blue << 16) | (alpha << 24);
}

Pixel::Pixel(uint32_t p) { n = p; }

bool Pixel::operator==(const Pixel &p) const { return n == p.n; }

bool Pixel::operator!=(const Pixel &p) const { return n != p.n; }

Pixel Pixel::operator*(const float i) const {
  float fR = std::min(255.0f, std::max(0.0f, float(r) * i));
  float fG = std::min(255.0f, std::max(0.0f, float(g) * i));
  float fB = std::min(255.0f, std::max(0.0f, float(b) * i));
  return Pixel(uint8_t(fR), uint8_t(fG), uint8_t(fB), a);
}

Pixel Pixel::operator/(const float i) const {
  float fR = std::min(255.0f, std::max(0.0f, float(r) / i));
  float fG = std::min(255.0f, std::max(0.0f, float(g) / i));
  float fB = std::min(255.0f, std::max(0.0f, float(b) / i));
  return Pixel(uint8_t(fR), uint8_t(fG), uint8_t(fB), a);
}

Pixel &Pixel::operator*=(const float i) {
  this->r = uint8_t(std::min(255.0f, std::max(0.0f, float(r) * i)));
  this->g = uint8_t(std::min(255.0f, std::max(0.0f, float(g) * i)));
  this->b = uint8_t(std::min(255.0f, std::max(0.0f, float(b) * i)));
  return *this;
}

Pixel &Pixel::operator/=(const float i) {
  this->r = uint8_t(std::min(255.0f, std::max(0.0f, float(r) / i)));
  this->g = uint8_t(std::min(255.0f, std::max(0.0f, float(g) / i)));
  this->b = uint8_t(std::min(255.0f, std::max(0.0f, float(b) / i)));
  return *this;
}

Pixel Pixel::operator+(const Pixel &p) const {
  uint8_t nR = uint8_t(std::min(255, std::max(0, int(r) + int(p.r))));
  uint8_t nG = uint8_t(std::min(255, std::max(0, int(g) + int(p.g))));
  uint8_t nB = uint8_t(std::min(255, std::max(0, int(b) + int(p.b))));
  return Pixel(nR, nG, nB, a);
}

Pixel Pixel::operator-(const Pixel &p) const {
  uint8_t nR = uint8_t(std::min(255, std::max(0, int(r) - int(p.r))));
  uint8_t nG = uint8_t(std::min(255, std::max(0, int(g) - int(p.g))));
  uint8_t nB = uint8_t(std::min(255, std::max(0, int(b) - int(p.b))));
  return Pixel(nR, nG, nB, a);
}

Pixel &Pixel::operator+=(const Pixel &p) {
  this->r = uint8_t(std::min(255, std::max(0, int(r) + int(p.r))));
  this->g = uint8_t(std::min(255, std::max(0, int(g) + int(p.g))));
  this->b = uint8_t(std::min(255, std::max(0, int(b) + int(p.b))));
  return *this;
}

Pixel &Pixel::operator-=(const Pixel &p) {
  this->r = uint8_t(std::min(255, std::max(0, int(r) - int(p.r))));
  this->g = uint8_t(std::min(255, std::max(0, int(g) - int(p.g))));
  this->b = uint8_t(std::min(255, std::max(0, int(b) - int(p.b))));
  return *this;
}

Pixel Pixel::inv() const {
  uint8_t nR = uint8_t(std::min(255, std::max(0, 255 - int(r))));
  uint8_t nG = uint8_t(std::min(255, std::max(0, 255 - int(g))));
  uint8_t nB = uint8_t(std::min(255, std::max(0, 255 - int(b))));
  return Pixel(nR, nG, nB, a);
}

Pixel PixelF(float red, float green, float blue, float alpha) {
  return Pixel(uint8_t(red * 255.0f), uint8_t(green * 255.0f),
               uint8_t(blue * 255.0f), uint8_t(alpha * 255.0f));
}

Pixel PixelLerp(const olc::Pixel &p1, const olc::Pixel &p2, float t) {
  return (p2 * t) + p1 * (1.0f - t);
}

Sprite::Sprite() {
  width = 0;
  height = 0;
}

Sprite::Sprite(const std::string &sImageFile, olc::ResourcePack *pack) {
  LoadFromFile(sImageFile, pack);
}

Sprite::Sprite(int32_t w, int32_t h) {
  width = w;
  height = h;
  pColData.resize(width * height);
  pColData.resize(width * height, nDefaultPixel);
}

Sprite::~Sprite() { pColData.clear(); }
void Sprite::SetSampleMode(olc::Sprite::Mode mode) { modeSample = mode; }

Pixel Sprite::GetPixel(const olc::vi2d &a) const { return GetPixel(a.x, a.y); }

bool Sprite::SetPixel(const olc::vi2d &a, Pixel p) {
  return SetPixel(a.x, a.y, p);
}

Pixel Sprite::GetPixel(int32_t x, int32_t y) const {
  if (modeSample == olc::Sprite::Mode::NORMAL) {
    if (x >= 0 && x < width && y >= 0 && y < height)
      return pColData[y * width + x];
    else
      return Pixel(0, 0, 0, 0);
  } else {
    return pColData[abs(y % height) * width + abs(x % width)];
  }
}

bool Sprite::SetPixel(int32_t x, int32_t y, Pixel p) {
  if (x >= 0 && x < width && y >= 0 && y < height) {
    pColData[y * width + x] = p;
    return true;
  } else
    return false;
}

Pixel Sprite::Sample(float x, float y) const {
  int32_t sx = std::min((int32_t)((x * (float)width)), width - 1);
  int32_t sy = std::min((int32_t)((y * (float)height)), height - 1);
  return GetPixel(sx, sy);
}

Pixel Sprite::SampleBL(float u, float v) const {
  u = u * width - 0.5f;
  v = v * height - 0.5f;
  int x = (int)floor(u);
  int y = (int)floor(v);
  float u_ratio = u - x;
  float v_ratio = v - y;
  float u_opposite = 1 - u_ratio;
  float v_opposite = 1 - v_ratio;

  olc::Pixel p1 = GetPixel(std::max(x, 0), std::max(y, 0));
  olc::Pixel p2 = GetPixel(std::min(x + 1, (int)width - 1), std::max(y, 0));
  olc::Pixel p3 = GetPixel(std::max(x, 0), std::min(y + 1, (int)height - 1));
  olc::Pixel p4 = GetPixel(std::min(x + 1, (int)width - 1),
                           std::min(y + 1, (int)height - 1));

  return olc::Pixel(
      (uint8_t)((p1.r * u_opposite + p2.r * u_ratio) * v_opposite +
                (p3.r * u_opposite + p4.r * u_ratio) * v_ratio),
      (uint8_t)((p1.g * u_opposite + p2.g * u_ratio) * v_opposite +
                (p3.g * u_opposite + p4.g * u_ratio) * v_ratio),
      (uint8_t)((p1.b * u_opposite + p2.b * u_ratio) * v_opposite +
                (p3.b * u_opposite + p4.b * u_ratio) * v_ratio));
}

Pixel *Sprite::GetData() { return pColData.data(); }

olc::rcode Sprite::LoadFromFile(const std::string &sImageFile,
                                olc::ResourcePack *pack) {
  (void)(pack);
  return loader->LoadImageResource(this, sImageFile, pack);
}

olc::Sprite *Sprite::Duplicate() {
  olc::Sprite *spr = new olc::Sprite(width, height);
  std::memcpy(spr->GetData(), GetData(), width * height * sizeof(olc::Pixel));
  spr->modeSample = modeSample;
  return spr;
}

olc::Sprite *Sprite::Duplicate(const olc::vi2d &vPos, const olc::vi2d &vSize) {
  olc::Sprite *spr = new olc::Sprite(vSize.x, vSize.y);
  for (int y = 0; y < vSize.y; y++)
    for (int x = 0; x < vSize.x; x++)
      spr->SetPixel(x, y, GetPixel(vPos.x + x, vPos.y + y));
  return spr;
}

Decal::Decal(olc::Sprite *spr, bool filter, bool clamp) {
  id = -1;
  if (spr == nullptr)
    return;
  sprite = spr;
  id = renderer->CreateTexture(sprite->width, sprite->height, filter, clamp);
  Update();
}

Decal::Decal(const uint32_t nExistingTextureResource, olc::Sprite *spr) {
  if (spr == nullptr)
    return;
  id = nExistingTextureResource;
}

void Decal::Update() {
  if (sprite == nullptr)
    return;
  vUVScale = {1.0f / float(sprite->width), 1.0f / float(sprite->height)};
  renderer->ApplyTexture(id);
  renderer->UpdateTexture(id, sprite);
}

void Decal::UpdateSprite() {
  if (sprite == nullptr)
    return;
  renderer->ApplyTexture(id);
  renderer->ReadTexture(id, sprite);
}

Decal::~Decal() {
  if (id != -1) {
    renderer->DeleteTexture(id);
    id = -1;
  }
}

void Renderable::Create(uint32_t width, uint32_t height, bool filter,
                        bool clamp) {
  pSprite = std::make_unique<olc::Sprite>(width, height);
  pDecal = std::make_unique<olc::Decal>(pSprite.get(), filter, clamp);
}

olc::rcode Renderable::Load(const std::string &sFile, ResourcePack *pack,
                            bool filter, bool clamp) {
  pSprite = std::make_unique<olc::Sprite>();
  if (pSprite->LoadFromFile(sFile, pack) == olc::rcode::OK) {
    pDecal = std::make_unique<olc::Decal>(pSprite.get(), filter, clamp);
    return olc::rcode::OK;
  } else {
    pSprite.release();
    pSprite = nullptr;
    return olc::rcode::NO_FILE;
  }
}

olc::Decal *Renderable::Decal() const { return pDecal.get(); }

olc::Sprite *Renderable::Sprite() const { return pSprite.get(); }
ResourceBuffer::ResourceBuffer(std::ifstream &ifs, uint32_t offset,
                               uint32_t size) {
  vMemory.resize(size);
  ifs.seekg(offset);
  ifs.read(vMemory.data(), vMemory.size());
  setg(vMemory.data(), vMemory.data(), vMemory.data() + size);
}

ResourcePack::ResourcePack() {}
ResourcePack::~ResourcePack() { baseFile.close(); }

bool ResourcePack::AddFile(const std::string &sFile) {
  const std::string file = makeposix(sFile);

  if (_gfs::exists(file)) {
    sResourceFile e;
    e.nSize = (uint32_t)_gfs::file_size(file);
    e.nOffset = 0;
    mapFiles[file] = e;
    return true;
  }
  return false;
}

bool ResourcePack::LoadPack(const std::string &sFile, const std::string &sKey) {

  baseFile.open(sFile, std::ifstream::binary);
  if (!baseFile.is_open())
    return false;

  uint32_t nIndexSize = 0;
  baseFile.read((char *)&nIndexSize, sizeof(uint32_t));

  std::vector<char> buffer(nIndexSize);
  for (uint32_t j = 0; j < nIndexSize; j++)
    buffer[j] = baseFile.get();

  std::vector<char> decoded = scramble(buffer, sKey);
  size_t pos = 0;
  auto read = [&decoded, &pos](char *dst, size_t size) {
    memcpy((void *)dst, (const void *)(decoded.data() + pos), size);
    pos += size;
  };

  auto get = [&read]() -> int {
    char c;
    read(&c, 1);
    return c;
  };

  uint32_t nMapEntries = 0;
  read((char *)&nMapEntries, sizeof(uint32_t));
  for (uint32_t i = 0; i < nMapEntries; i++) {
    uint32_t nFilePathSize = 0;
    read((char *)&nFilePathSize, sizeof(uint32_t));

    std::string sFileName(nFilePathSize, ' ');
    for (uint32_t j = 0; j < nFilePathSize; j++)
      sFileName[j] = get();

    sResourceFile e;
    read((char *)&e.nSize, sizeof(uint32_t));
    read((char *)&e.nOffset, sizeof(uint32_t));
    mapFiles[sFileName] = e;
  }

  return true;
}

bool ResourcePack::SavePack(const std::string &sFile, const std::string &sKey) {

  std::ofstream ofs(sFile, std::ofstream::binary);
  if (!ofs.is_open())
    return false;

  uint32_t nIndexSize = 0;
  ofs.write((char *)&nIndexSize, sizeof(uint32_t));
  uint32_t nMapSize = uint32_t(mapFiles.size());
  ofs.write((char *)&nMapSize, sizeof(uint32_t));
  for (auto &e : mapFiles) {

    size_t nPathSize = e.first.size();
    ofs.write((char *)&nPathSize, sizeof(uint32_t));
    ofs.write(e.first.c_str(), nPathSize);

    ofs.write((char *)&e.second.nSize, sizeof(uint32_t));
    ofs.write((char *)&e.second.nOffset, sizeof(uint32_t));
  }

  std::streampos offset = ofs.tellp();
  nIndexSize = (uint32_t)offset;
  for (auto &e : mapFiles) {

    e.second.nOffset = (uint32_t)offset;

    std::vector<uint8_t> vBuffer(e.second.nSize);
    std::ifstream i(e.first, std::ifstream::binary);
    i.read((char *)vBuffer.data(), e.second.nSize);
    i.close();

    ofs.write((char *)vBuffer.data(), e.second.nSize);
    offset += e.second.nSize;
  }

  std::vector<char> stream;
  auto write = [&stream](const char *data, size_t size) {
    size_t sizeNow = stream.size();
    stream.resize(sizeNow + size);
    memcpy(stream.data() + sizeNow, data, size);
  };

  write((char *)&nMapSize, sizeof(uint32_t));
  for (auto &e : mapFiles) {

    size_t nPathSize = e.first.size();
    write((char *)&nPathSize, sizeof(uint32_t));
    write(e.first.c_str(), nPathSize);

    write((char *)&e.second.nSize, sizeof(uint32_t));
    write((char *)&e.second.nOffset, sizeof(uint32_t));
  }
  std::vector<char> sIndexString = scramble(stream, sKey);
  uint32_t nIndexStringLen = uint32_t(sIndexString.size());

  ofs.seekp(0, std::ios::beg);
  ofs.write((char *)&nIndexStringLen, sizeof(uint32_t));
  ofs.write(sIndexString.data(), nIndexStringLen);
  ofs.close();
  return true;
}

ResourceBuffer ResourcePack::GetFileBuffer(const std::string &sFile) {
  return ResourceBuffer(baseFile, mapFiles[sFile].nOffset,
                        mapFiles[sFile].nSize);
}

bool ResourcePack::Loaded() { return baseFile.is_open(); }

std::vector<char> ResourcePack::scramble(const std::vector<char> &data,
                                         const std::string &key) {
  if (key.empty())
    return data;
  std::vector<char> o;
  size_t c = 0;
  for (auto s : data)
    o.push_back(s ^ key[(c++) % key.size()]);
  return o;
};

std::string ResourcePack::makeposix(const std::string &path) {
  std::string o;
  for (auto s : path)
    o += std::string(1, s == '\\' ? '/' : s);
  return o;
};

PixelGameEngine::PixelGameEngine() {
  sAppName = "Undefined";
  olc::PGEX::pge = this;

  olc_ConfigureSystem();
}

PixelGameEngine::~PixelGameEngine() {}

olc::rcode PixelGameEngine::Construct(int32_t screen_w, int32_t screen_h,
                                      int32_t pixel_w, int32_t pixel_h,
                                      bool full_screen, bool vsync,
                                      bool cohesion) {
  bPixelCohesion = cohesion;
  vScreenSize = {screen_w, screen_h};
  vInvScreenSize = {1.0f / float(screen_w), 1.0f / float(screen_h)};
  vPixelSize = {pixel_w, pixel_h};
  vWindowSize = vScreenSize * vPixelSize;
  bFullScreen = full_screen;
  bEnableVSYNC = vsync;
  vPixel = 2.0f / vScreenSize;

  if (vPixelSize.x <= 0 || vPixelSize.y <= 0 || vScreenSize.x <= 0 ||
      vScreenSize.y <= 0)
    return olc::FAIL;
  return olc::OK;
}

void PixelGameEngine::SetScreenSize(int w, int h) {
  vScreenSize = {w, h};
  vInvScreenSize = {1.0f / float(w), 1.0f / float(h)};
  for (auto &layer : vLayers) {
    delete layer.pDrawTarget;
    layer.pDrawTarget = new Sprite(vScreenSize.x, vScreenSize.y);
    layer.bUpdate = true;
  }
  SetDrawTarget(nullptr);
  renderer->ClearBuffer(olc::BLACK, true);
  renderer->DisplayFrame();
  renderer->ClearBuffer(olc::BLACK, true);
  renderer->UpdateViewport(vViewPos, vViewSize);
}

olc::rcode PixelGameEngine::Start() {
  if (platform->ApplicationStartUp() != olc::OK)
    return olc::FAIL;

  if (platform->CreateWindowPane({30, 30}, vWindowSize, bFullScreen) != olc::OK)
    return olc::FAIL;
  olc_UpdateWindowSize(vWindowSize.x, vWindowSize.y);

  bAtomActive = true;
  std::thread t = std::thread(&PixelGameEngine::EngineThread, this);

  platform->StartSystemEventLoop();

  t.join();

  if (platform->ApplicationCleanUp() != olc::OK)
    return olc::FAIL;

  return olc::OK;
}

void PixelGameEngine::SetDrawTarget(Sprite *target) {
  if (target) {
    pDrawTarget = target;
  } else {
    nTargetLayer = 0;
    pDrawTarget = vLayers[0].pDrawTarget;
  }
}

void PixelGameEngine::SetDrawTarget(uint8_t layer) {
  if (layer < vLayers.size()) {
    pDrawTarget = vLayers[layer].pDrawTarget;
    vLayers[layer].bUpdate = true;
    nTargetLayer = layer;
  }
}

void PixelGameEngine::EnableLayer(uint8_t layer, bool b) {
  if (layer < vLayers.size())
    vLayers[layer].bShow = b;
}

void PixelGameEngine::SetLayerOffset(uint8_t layer, const olc::vf2d &offset) {
  SetLayerOffset(layer, offset.x, offset.y);
}

void PixelGameEngine::SetLayerOffset(uint8_t layer, float x, float y) {
  if (layer < vLayers.size())
    vLayers[layer].vOffset = {x, y};
}

void PixelGameEngine::SetLayerScale(uint8_t layer, const olc::vf2d &scale) {
  SetLayerScale(layer, scale.x, scale.y);
}

void PixelGameEngine::SetLayerScale(uint8_t layer, float x, float y) {
  if (layer < vLayers.size())
    vLayers[layer].vScale = {x, y};
}

void PixelGameEngine::SetLayerTint(uint8_t layer, const olc::Pixel &tint) {
  if (layer < vLayers.size())
    vLayers[layer].tint = tint;
}

void PixelGameEngine::SetLayerCustomRenderFunction(uint8_t layer,
                                                   std::function<void()> f) {
  if (layer < vLayers.size())
    vLayers[layer].funcHook = f;
}

std::vector<LayerDesc> &PixelGameEngine::GetLayers() { return vLayers; }

uint32_t PixelGameEngine::CreateLayer() {
  LayerDesc ld;
  ld.pDrawTarget = new olc::Sprite(vScreenSize.x, vScreenSize.y);
  ld.nResID = renderer->CreateTexture(vScreenSize.x, vScreenSize.y);
  renderer->UpdateTexture(ld.nResID, ld.pDrawTarget);
  vLayers.push_back(ld);
  return uint32_t(vLayers.size()) - 1;
}

Sprite *PixelGameEngine::GetDrawTarget() const { return pDrawTarget; }

int32_t PixelGameEngine::GetDrawTargetWidth() const {
  if (pDrawTarget)
    return pDrawTarget->width;
  else
    return 0;
}

int32_t PixelGameEngine::GetDrawTargetHeight() const {
  if (pDrawTarget)
    return pDrawTarget->height;
  else
    return 0;
}

uint32_t PixelGameEngine::GetFPS() const { return nLastFPS; }

bool PixelGameEngine::IsFocused() const { return bHasInputFocus; }

HWButton PixelGameEngine::GetKey(Key k) const { return pKeyboardState[k]; }

HWButton PixelGameEngine::GetMouse(uint32_t b) const { return pMouseState[b]; }

int32_t PixelGameEngine::GetMouseX() const { return vMousePos.x; }

int32_t PixelGameEngine::GetMouseY() const { return vMousePos.y; }

const olc::vi2d &PixelGameEngine::GetMousePos() const { return vMousePos; }

int32_t PixelGameEngine::GetMouseWheel() const { return nMouseWheelDelta; }

int32_t PixelGameEngine::ScreenWidth() const { return vScreenSize.x; }

int32_t PixelGameEngine::ScreenHeight() const { return vScreenSize.y; }

float PixelGameEngine::GetElapsedTime() const { return fLastElapsed; }

const olc::vi2d &PixelGameEngine::GetWindowSize() const { return vWindowSize; }

const olc::vi2d &PixelGameEngine::GetPixelSize() const { return vPixelSize; }

const olc::vi2d &PixelGameEngine::GetScreenPixelSize() const {
  return vScreenPixelSize;
}

const olc::vi2d &PixelGameEngine::GetWindowMouse() const {
  return vMouseWindowPos;
}

bool PixelGameEngine::Draw(const olc::vi2d &pos, Pixel p) {
  return Draw(pos.x, pos.y, p);
}

bool PixelGameEngine::Draw(int32_t x, int32_t y, Pixel p) {
  if (!pDrawTarget)
    return false;

  if (nPixelMode == Pixel::NORMAL) {
    return pDrawTarget->SetPixel(x, y, p);
  }

  if (nPixelMode == Pixel::MASK) {
    if (p.a == 255)
      return pDrawTarget->SetPixel(x, y, p);
  }

  if (nPixelMode == Pixel::ALPHA) {
    Pixel d = pDrawTarget->GetPixel(x, y);
    float a = (float)(p.a / 255.0f) * fBlendFactor;
    float c = 1.0f - a;
    float r = a * (float)p.r + c * (float)d.r;
    float g = a * (float)p.g + c * (float)d.g;
    float b = a * (float)p.b + c * (float)d.b;
    return pDrawTarget->SetPixel(x, y,
                                 Pixel((uint8_t)r, (uint8_t)g, (uint8_t)b));
  }

  if (nPixelMode == Pixel::CUSTOM) {
    return pDrawTarget->SetPixel(
        x, y, funcPixelMode(x, y, p, pDrawTarget->GetPixel(x, y)));
  }

  return false;
}

void PixelGameEngine::DrawLine(const olc::vi2d &pos1, const olc::vi2d &pos2,
                               Pixel p, uint32_t pattern) {
  DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, p, pattern);
}

void PixelGameEngine::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                               Pixel p, uint32_t pattern) {
  int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
  dx = x2 - x1;
  dy = y2 - y1;

  auto rol = [&](void) {
    pattern = (pattern << 1) | (pattern >> 31);
    return pattern & 1;
  };

  if (dx == 0) {
    if (y2 < y1)
      std::swap(y1, y2);
    for (y = y1; y <= y2; y++)
      if (rol())
        Draw(x1, y, p);
    return;
  }

  if (dy == 0) {
    if (x2 < x1)
      std::swap(x1, x2);
    for (x = x1; x <= x2; x++)
      if (rol())
        Draw(x, y1, p);
    return;
  }

  dx1 = abs(dx);
  dy1 = abs(dy);
  px = 2 * dy1 - dx1;
  py = 2 * dx1 - dy1;
  if (dy1 <= dx1) {
    if (dx >= 0) {
      x = x1;
      y = y1;
      xe = x2;
    } else {
      x = x2;
      y = y2;
      xe = x1;
    }

    if (rol())
      Draw(x, y, p);

    for (i = 0; x < xe; i++) {
      x = x + 1;
      if (px < 0)
        px = px + 2 * dy1;
      else {
        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
          y = y + 1;
        else
          y = y - 1;
        px = px + 2 * (dy1 - dx1);
      }
      if (rol())
        Draw(x, y, p);
    }
  } else {
    if (dy >= 0) {
      x = x1;
      y = y1;
      ye = y2;
    } else {
      x = x2;
      y = y2;
      ye = y1;
    }

    if (rol())
      Draw(x, y, p);

    for (i = 0; y < ye; i++) {
      y = y + 1;
      if (py <= 0)
        py = py + 2 * dx1;
      else {
        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
          x = x + 1;
        else
          x = x - 1;
        py = py + 2 * (dx1 - dy1);
      }
      if (rol())
        Draw(x, y, p);
    }
  }
}

void PixelGameEngine::DrawCircle(const olc::vi2d &pos, int32_t radius, Pixel p,
                                 uint8_t mask) {
  DrawCircle(pos.x, pos.y, radius, p, mask);
}

void PixelGameEngine::DrawCircle(int32_t x, int32_t y, int32_t radius, Pixel p,
                                 uint8_t mask) {
  if (radius < 0 || x < -radius || y < -radius ||
      x - GetDrawTargetWidth() > radius || y - GetDrawTargetHeight() > radius)
    return;

  if (radius > 0) {
    int x0 = 0;
    int y0 = radius;
    int d = 3 - 2 * radius;

    while (y0 >= x0) {

      if (mask & 0x01)
        Draw(x + x0, y - y0, p);
      if (mask & 0x04)
        Draw(x + y0, y + x0, p);
      if (mask & 0x10)
        Draw(x - x0, y + y0, p);
      if (mask & 0x40)
        Draw(x - y0, y - x0, p);
      if (x0 != 0 && x0 != y0) {
        if (mask & 0x02)
          Draw(x + y0, y - x0, p);
        if (mask & 0x08)
          Draw(x + x0, y + y0, p);
        if (mask & 0x20)
          Draw(x - y0, y + x0, p);
        if (mask & 0x80)
          Draw(x - x0, y - y0, p);
      }

      if (d < 0)
        d += 4 * x0++ + 6;
      else
        d += 4 * (x0++ - y0--) + 10;
    }
  } else
    Draw(x, y, p);
}

void PixelGameEngine::FillCircle(const olc::vi2d &pos, int32_t radius,
                                 Pixel p) {
  FillCircle(pos.x, pos.y, radius, p);
}

void PixelGameEngine::FillCircle(int32_t x, int32_t y, int32_t radius,
                                 Pixel p) {
  if (radius < 0 || x < -radius || y < -radius ||
      x - GetDrawTargetWidth() > radius || y - GetDrawTargetHeight() > radius)
    return;

  if (radius > 0) {
    int x0 = 0;
    int y0 = radius;
    int d = 3 - 2 * radius;

    auto drawline = [&](int sx, int ex, int y) {
      for (int x = sx; x <= ex; x++)
        Draw(x, y, p);
    };

    while (y0 >= x0) {
      drawline(x - y0, x + y0, y - x0);
      if (x0 > 0)
        drawline(x - y0, x + y0, y + x0);

      if (d < 0)
        d += 4 * x0++ + 6;
      else {
        if (x0 != y0) {
          drawline(x - x0, x + x0, y - y0);
          drawline(x - x0, x + x0, y + y0);
        }
        d += 4 * (x0++ - y0--) + 10;
      }
    }
  } else
    Draw(x, y, p);
}

void PixelGameEngine::DrawRect(const olc::vi2d &pos, const olc::vi2d &size,
                               Pixel p) {
  DrawRect(pos.x, pos.y, size.x, size.y, p);
}

void PixelGameEngine::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h,
                               Pixel p) {
  DrawLine(x, y, x + w, y, p);
  DrawLine(x + w, y, x + w, y + h, p);
  DrawLine(x + w, y + h, x, y + h, p);
  DrawLine(x, y + h, x, y, p);
}

void PixelGameEngine::Clear(Pixel p) {
  int pixels = GetDrawTargetWidth() * GetDrawTargetHeight();
  Pixel *m = GetDrawTarget()->GetData();
  for (int i = 0; i < pixels; i++)
    m[i] = p;
}

void PixelGameEngine::ClearBuffer(Pixel p, bool bDepth) {
  renderer->ClearBuffer(p, bDepth);
}

olc::Sprite *PixelGameEngine::GetFontSprite() { return fontSprite; }

void PixelGameEngine::FillRect(const olc::vi2d &pos, const olc::vi2d &size,
                               Pixel p) {
  FillRect(pos.x, pos.y, size.x, size.y, p);
}

void PixelGameEngine::FillRect(int32_t x, int32_t y, int32_t w, int32_t h,
                               Pixel p) {
  int32_t x2 = x + w;
  int32_t y2 = y + h;

  if (x < 0)
    x = 0;
  if (x >= (int32_t)GetDrawTargetWidth())
    x = (int32_t)GetDrawTargetWidth();
  if (y < 0)
    y = 0;
  if (y >= (int32_t)GetDrawTargetHeight())
    y = (int32_t)GetDrawTargetHeight();

  if (x2 < 0)
    x2 = 0;
  if (x2 >= (int32_t)GetDrawTargetWidth())
    x2 = (int32_t)GetDrawTargetWidth();
  if (y2 < 0)
    y2 = 0;
  if (y2 >= (int32_t)GetDrawTargetHeight())
    y2 = (int32_t)GetDrawTargetHeight();

  for (int i = x; i < x2; i++)
    for (int j = y; j < y2; j++)
      Draw(i, j, p);
}

void PixelGameEngine::DrawTriangle(const olc::vi2d &pos1, const olc::vi2d &pos2,
                                   const olc::vi2d &pos3, Pixel p) {
  DrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, p);
}

void PixelGameEngine::DrawTriangle(int32_t x1, int32_t y1, int32_t x2,
                                   int32_t y2, int32_t x3, int32_t y3,
                                   Pixel p) {
  DrawLine(x1, y1, x2, y2, p);
  DrawLine(x2, y2, x3, y3, p);
  DrawLine(x3, y3, x1, y1, p);
}

void PixelGameEngine::FillTriangle(const olc::vi2d &pos1, const olc::vi2d &pos2,
                                   const olc::vi2d &pos3, Pixel p) {
  FillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, p);
}

void PixelGameEngine::FillTriangle(int32_t x1, int32_t y1, int32_t x2,
                                   int32_t y2, int32_t x3, int32_t y3,
                                   Pixel p) {
  auto drawline = [&](int sx, int ex, int ny) {
    for (int i = sx; i <= ex; i++)
      Draw(i, ny, p);
  };

  int t1x, t2x, y, minx, maxx, t1xp, t2xp;
  bool changed1 = false;
  bool changed2 = false;
  int signx1, signx2, dx1, dy1, dx2, dy2;
  int e1, e2;

  if (y1 > y2) {
    std::swap(y1, y2);
    std::swap(x1, x2);
  }
  if (y1 > y3) {
    std::swap(y1, y3);
    std::swap(x1, x3);
  }
  if (y2 > y3) {
    std::swap(y2, y3);
    std::swap(x2, x3);
  }

  t1x = t2x = x1;
  y = y1;
  dx1 = (int)(x2 - x1);
  if (dx1 < 0) {
    dx1 = -dx1;
    signx1 = -1;
  } else
    signx1 = 1;
  dy1 = (int)(y2 - y1);

  dx2 = (int)(x3 - x1);
  if (dx2 < 0) {
    dx2 = -dx2;
    signx2 = -1;
  } else
    signx2 = 1;
  dy2 = (int)(y3 - y1);

  if (dy1 > dx1) {
    std::swap(dx1, dy1);
    changed1 = true;
  }
  if (dy2 > dx2) {
    std::swap(dy2, dx2);
    changed2 = true;
  }

  e2 = (int)(dx2 >> 1);

  if (y1 == y2)
    goto next;
  e1 = (int)(dx1 >> 1);

  for (int i = 0; i < dx1;) {
    t1xp = 0;
    t2xp = 0;
    if (t1x < t2x) {
      minx = t1x;
      maxx = t2x;
    } else {
      minx = t2x;
      maxx = t1x;
    }

    while (i < dx1) {
      i++;
      e1 += dy1;
      while (e1 >= dx1) {
        e1 -= dx1;
        if (changed1)
          t1xp = signx1;
        else
          goto next1;
      }
      if (changed1)
        break;
      else
        t1x += signx1;
    }

  next1:

    while (1) {
      e2 += dy2;
      while (e2 >= dx2) {
        e2 -= dx2;
        if (changed2)
          t2xp = signx2;
        else
          goto next2;
      }
      if (changed2)
        break;
      else
        t2x += signx2;
    }
  next2:
    if (minx > t1x)
      minx = t1x;
    if (minx > t2x)
      minx = t2x;
    if (maxx < t1x)
      maxx = t1x;
    if (maxx < t2x)
      maxx = t2x;
    drawline(minx, maxx, y);

    if (!changed1)
      t1x += signx1;
    t1x += t1xp;
    if (!changed2)
      t2x += signx2;
    t2x += t2xp;
    y += 1;
    if (y == y2)
      break;
  }
next:

  dx1 = (int)(x3 - x2);
  if (dx1 < 0) {
    dx1 = -dx1;
    signx1 = -1;
  } else
    signx1 = 1;
  dy1 = (int)(y3 - y2);
  t1x = x2;

  if (dy1 > dx1) {
    std::swap(dy1, dx1);
    changed1 = true;
  } else
    changed1 = false;

  e1 = (int)(dx1 >> 1);

  for (int i = 0; i <= dx1; i++) {
    t1xp = 0;
    t2xp = 0;
    if (t1x < t2x) {
      minx = t1x;
      maxx = t2x;
    } else {
      minx = t2x;
      maxx = t1x;
    }

    while (i < dx1) {
      e1 += dy1;
      while (e1 >= dx1) {
        e1 -= dx1;
        if (changed1) {
          t1xp = signx1;
          break;
        } else
          goto next3;
      }
      if (changed1)
        break;
      else
        t1x += signx1;
      if (i < dx1)
        i++;
    }
  next3:

    while (t2x != x3) {
      e2 += dy2;
      while (e2 >= dx2) {
        e2 -= dx2;
        if (changed2)
          t2xp = signx2;
        else
          goto next4;
      }
      if (changed2)
        break;
      else
        t2x += signx2;
    }
  next4:

    if (minx > t1x)
      minx = t1x;
    if (minx > t2x)
      minx = t2x;
    if (maxx < t1x)
      maxx = t1x;
    if (maxx < t2x)
      maxx = t2x;
    drawline(minx, maxx, y);
    if (!changed1)
      t1x += signx1;
    t1x += t1xp;
    if (!changed2)
      t2x += signx2;
    t2x += t2xp;
    y += 1;
    if (y > y3)
      return;
  }
}

void PixelGameEngine::DrawSprite(const olc::vi2d &pos, Sprite *sprite,
                                 uint32_t scale, uint8_t flip) {
  DrawSprite(pos.x, pos.y, sprite, scale, flip);
}

void PixelGameEngine::DrawSprite(int32_t x, int32_t y, Sprite *sprite,
                                 uint32_t scale, uint8_t flip) {
  if (sprite == nullptr)
    return;

  int32_t fxs = 0, fxm = 1, fx = 0;
  int32_t fys = 0, fym = 1, fy = 0;
  if (flip & olc::Sprite::Flip::HORIZ) {
    fxs = sprite->width - 1;
    fxm = -1;
  }
  if (flip & olc::Sprite::Flip::VERT) {
    fys = sprite->height - 1;
    fym = -1;
  }

  if (scale > 1) {
    fx = fxs;
    for (int32_t i = 0; i < sprite->width; i++, fx += fxm) {
      fy = fys;
      for (int32_t j = 0; j < sprite->height; j++, fy += fym)
        for (uint32_t is = 0; is < scale; is++)
          for (uint32_t js = 0; js < scale; js++)
            Draw(x + (i * scale) + is, y + (j * scale) + js,
                 sprite->GetPixel(fx, fy));
    }
  } else {
    fx = fxs;
    for (int32_t i = 0; i < sprite->width; i++, fx += fxm) {
      fy = fys;
      for (int32_t j = 0; j < sprite->height; j++, fy += fym)
        Draw(x + i, y + j, sprite->GetPixel(fx, fy));
    }
  }
}

void PixelGameEngine::DrawPartialSprite(const olc::vi2d &pos, Sprite *sprite,
                                        const olc::vi2d &sourcepos,
                                        const olc::vi2d &size, uint32_t scale,
                                        uint8_t flip) {
  DrawPartialSprite(pos.x, pos.y, sprite, sourcepos.x, sourcepos.y, size.x,
                    size.y, scale, flip);
}

void PixelGameEngine::DrawPartialSprite(int32_t x, int32_t y, Sprite *sprite,
                                        int32_t ox, int32_t oy, int32_t w,
                                        int32_t h, uint32_t scale,
                                        uint8_t flip) {
  if (sprite == nullptr)
    return;

  int32_t fxs = 0, fxm = 1, fx = 0;
  int32_t fys = 0, fym = 1, fy = 0;
  if (flip & olc::Sprite::Flip::HORIZ) {
    fxs = w - 1;
    fxm = -1;
  }
  if (flip & olc::Sprite::Flip::VERT) {
    fys = h - 1;
    fym = -1;
  }

  if (scale > 1) {
    fx = fxs;
    for (int32_t i = 0; i < w; i++, fx += fxm) {
      fy = fys;
      for (int32_t j = 0; j < h; j++, fy += fym)
        for (uint32_t is = 0; is < scale; is++)
          for (uint32_t js = 0; js < scale; js++)
            Draw(x + (i * scale) + is, y + (j * scale) + js,
                 sprite->GetPixel(fx + ox, fy + oy));
    }
  } else {
    fx = fxs;
    for (int32_t i = 0; i < w; i++, fx += fxm) {
      fy = fys;
      for (int32_t j = 0; j < h; j++, fy += fym)
        Draw(x + i, y + j, sprite->GetPixel(fx + ox, fy + oy));
    }
  }
}

void PixelGameEngine::SetDecalMode(const olc::DecalMode &mode) {
  nDecalMode = mode;
}

void PixelGameEngine::DrawPartialDecal(const olc::vf2d &pos, olc::Decal *decal,
                                       const olc::vf2d &source_pos,
                                       const olc::vf2d &source_size,
                                       const olc::vf2d &scale,
                                       const olc::Pixel &tint) {
  olc::vf2d vScreenSpacePos = {
      (std::floor(pos.x) * vInvScreenSize.x) * 2.0f - 1.0f,
      ((std::floor(pos.y) * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};

  olc::vf2d vScreenSpaceDim = {
      vScreenSpacePos.x + (2.0f * source_size.x * vInvScreenSize.x) * scale.x,
      vScreenSpacePos.y - (2.0f * source_size.y * vInvScreenSize.y) * scale.y};

  DecalInstance di;
  di.points = 4;
  di.decal = decal;
  di.tint = {tint, tint, tint, tint};
  di.pos = {{vScreenSpacePos.x, vScreenSpacePos.y},
            {vScreenSpacePos.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpacePos.y}};
  olc::vf2d uvtl = source_pos * decal->vUVScale;
  olc::vf2d uvbr = uvtl + (source_size * decal->vUVScale);
  di.uv = {
      {uvtl.x, uvtl.y}, {uvtl.x, uvbr.y}, {uvbr.x, uvbr.y}, {uvbr.x, uvtl.y}};
  di.w = {1, 1, 1, 1};
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawPartialDecal(const olc::vf2d &pos,
                                       const olc::vf2d &size, olc::Decal *decal,
                                       const olc::vf2d &source_pos,
                                       const olc::vf2d &source_size,
                                       const olc::Pixel &tint) {
  olc::vf2d vScreenSpacePos = {
      (std::floor(pos.x) * vInvScreenSize.x) * 2.0f - 1.0f,
      ((std::floor(pos.y) * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};

  olc::vf2d vScreenSpaceDim = {
      vScreenSpacePos.x + (2.0f * size.x * vInvScreenSize.x),
      vScreenSpacePos.y - (2.0f * size.y * vInvScreenSize.y)};

  DecalInstance di;
  di.points = 4;
  di.decal = decal;
  di.tint = {tint, tint, tint, tint};
  di.pos = {{vScreenSpacePos.x, vScreenSpacePos.y},
            {vScreenSpacePos.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpacePos.y}};
  olc::vf2d uvtl = (source_pos)*decal->vUVScale;
  olc::vf2d uvbr = uvtl + ((source_size)*decal->vUVScale);
  di.uv = {
      {uvtl.x, uvtl.y}, {uvtl.x, uvbr.y}, {uvbr.x, uvbr.y}, {uvbr.x, uvtl.y}};
  di.w = {1, 1, 1, 1};
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawDecal(const olc::vf2d &pos, olc::Decal *decal,
                                const olc::vf2d &scale,
                                const olc::Pixel &tint) {
  olc::vf2d vScreenSpacePos = {
      (std::floor(pos.x) * vInvScreenSize.x) * 2.0f - 1.0f,
      ((std::floor(pos.y) * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};

  olc::vf2d vScreenSpaceDim = {
      vScreenSpacePos.x +
          (2.0f * (float(decal->sprite->width) * vInvScreenSize.x)) * scale.x,
      vScreenSpacePos.y -
          (2.0f * (float(decal->sprite->height) * vInvScreenSize.y)) * scale.y};

  DecalInstance di;
  di.decal = decal;
  di.points = 4;
  di.tint = {tint, tint, tint, tint};
  di.pos = {{vScreenSpacePos.x, vScreenSpacePos.y},
            {vScreenSpacePos.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpaceDim.y},
            {vScreenSpaceDim.x, vScreenSpacePos.y}};
  di.uv = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};
  di.w = {1, 1, 1, 1};
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawExplicitDecal(olc::Decal *decal, const olc::vf2d *pos,
                                        const olc::vf2d *uv,
                                        const olc::Pixel *col,
                                        uint32_t elements) {
  DecalInstance di;
  di.decal = decal;
  di.pos.resize(elements);
  di.uv.resize(elements);
  di.w.resize(elements);
  di.tint.resize(elements);
  di.points = elements;
  for (uint32_t i = 0; i < elements; i++) {
    di.pos[i] = {(pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f,
                 ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};
    di.uv[i] = uv[i];
    di.tint[i] = col[i];
    di.w[i] = 1.0f;
  }
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawPolygonDecal(olc::Decal *decal,
                                       const std::vector<olc::vf2d> &pos,
                                       const std::vector<olc::vf2d> &uv,
                                       const olc::Pixel tint) {
  DecalInstance di;
  di.decal = decal;
  di.points = uint32_t(pos.size());
  di.pos.resize(di.points);
  di.uv.resize(di.points);
  di.w.resize(di.points);
  di.tint.resize(di.points);
  for (uint32_t i = 0; i < di.points; i++) {
    di.pos[i] = {(pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f,
                 ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};
    di.uv[i] = uv[i];
    di.tint[i] = tint;
    di.w[i] = 1.0f;
  }
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::FillRectDecal(const olc::vf2d &pos, const olc::vf2d &size,
                                    const olc::Pixel col) {
  std::array<olc::vf2d, 4> points = {
      {{pos}, {pos.x, pos.y + size.y}, {pos + size}, {pos.x + size.x, pos.y}}};
  std::array<olc::vf2d, 4> uvs = {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};
  std::array<olc::Pixel, 4> cols = {{col, col, col, col}};
  DrawExplicitDecal(nullptr, points.data(), uvs.data(), cols.data(), 4);
}

void PixelGameEngine::GradientFillRectDecal(
    const olc::vf2d &pos, const olc::vf2d &size, const olc::Pixel colTL,
    const olc::Pixel colBL, const olc::Pixel colBR, const olc::Pixel colTR) {
  std::array<olc::vf2d, 4> points = {
      {{pos}, {pos.x, pos.y + size.y}, {pos + size}, {pos.x + size.x, pos.y}}};
  std::array<olc::vf2d, 4> uvs = {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};
  std::array<olc::Pixel, 4> cols = {{colTL, colBL, colBR, colTR}};
  DrawExplicitDecal(nullptr, points.data(), uvs.data(), cols.data(), 4);
}

void PixelGameEngine::DrawRotatedDecal(const olc::vf2d &pos, olc::Decal *decal,
                                       const float fAngle,
                                       const olc::vf2d &center,
                                       const olc::vf2d &scale,
                                       const olc::Pixel &tint) {
  DecalInstance di;
  di.decal = decal;
  di.pos.resize(4);
  di.uv = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};
  di.w = {1, 1, 1, 1};
  di.tint = {tint, tint, tint, tint};
  di.points = 4;
  di.pos[0] = (olc::vf2d(0.0f, 0.0f) - center) * scale;
  di.pos[1] = (olc::vf2d(0.0f, float(decal->sprite->height)) - center) * scale;
  di.pos[2] =
      (olc::vf2d(float(decal->sprite->width), float(decal->sprite->height)) -
       center) *
      scale;
  di.pos[3] = (olc::vf2d(float(decal->sprite->width), 0.0f) - center) * scale;
  float c = cos(fAngle), s = sin(fAngle);
  for (int i = 0; i < 4; i++) {
    di.pos[i] = pos + olc::vf2d(di.pos[i].x * c - di.pos[i].y * s,
                                di.pos[i].x * s + di.pos[i].y * c);
    di.pos[i] = di.pos[i] * vInvScreenSize * 2.0f - olc::vf2d(1.0f, 1.0f);
    di.pos[i].y *= -1.0f;
    di.w[i] = 1;
  }
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawPartialRotatedDecal(
    const olc::vf2d &pos, olc::Decal *decal, const float fAngle,
    const olc::vf2d &center, const olc::vf2d &source_pos,
    const olc::vf2d &source_size, const olc::vf2d &scale,
    const olc::Pixel &tint) {
  DecalInstance di;
  di.decal = decal;
  di.points = 4;
  di.tint = {tint, tint, tint, tint};
  di.w = {1, 1, 1, 1};
  di.pos.resize(4);
  di.pos[0] = (olc::vf2d(0.0f, 0.0f) - center) * scale;
  di.pos[1] = (olc::vf2d(0.0f, source_size.y) - center) * scale;
  di.pos[2] = (olc::vf2d(source_size.x, source_size.y) - center) * scale;
  di.pos[3] = (olc::vf2d(source_size.x, 0.0f) - center) * scale;
  float c = cos(fAngle), s = sin(fAngle);
  for (int i = 0; i < 4; i++) {
    di.pos[i] = pos + olc::vf2d(di.pos[i].x * c - di.pos[i].y * s,
                                di.pos[i].x * s + di.pos[i].y * c);
    di.pos[i] = di.pos[i] * vInvScreenSize * 2.0f - olc::vf2d(1.0f, 1.0f);
    di.pos[i].y *= -1.0f;
  }

  olc::vf2d uvtl = source_pos * decal->vUVScale;
  olc::vf2d uvbr = uvtl + (source_size * decal->vUVScale);
  di.uv = {
      {uvtl.x, uvtl.y}, {uvtl.x, uvbr.y}, {uvbr.x, uvbr.y}, {uvbr.x, uvtl.y}};
  di.mode = nDecalMode;
  vLayers[nTargetLayer].vecDecalInstance.push_back(di);
}

void PixelGameEngine::DrawPartialWarpedDecal(olc::Decal *decal,
                                             const olc::vf2d *pos,
                                             const olc::vf2d &source_pos,
                                             const olc::vf2d &source_size,
                                             const olc::Pixel &tint) {
  DecalInstance di;
  di.points = 4;
  di.decal = decal;
  di.tint = {tint, tint, tint, tint};
  di.w = {1, 1, 1, 1};
  di.pos.resize(4);
  di.uv = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};
  olc::vf2d center;
  float rd = ((pos[2].x - pos[0].x) * (pos[3].y - pos[1].y) -
              (pos[3].x - pos[1].x) * (pos[2].y - pos[0].y));
  if (rd != 0) {
    olc::vf2d uvtl = source_pos * decal->vUVScale;
    olc::vf2d uvbr = uvtl + (source_size * decal->vUVScale);
    di.uv = {
        {uvtl.x, uvtl.y}, {uvtl.x, uvbr.y}, {uvbr.x, uvbr.y}, {uvbr.x, uvtl.y}};

    rd = 1.0f / rd;
    float rn = ((pos[3].x - pos[1].x) * (pos[0].y - pos[1].y) -
                (pos[3].y - pos[1].y) * (pos[0].x - pos[1].x)) *
               rd;
    float sn = ((pos[2].x - pos[0].x) * (pos[0].y - pos[1].y) -
                (pos[2].y - pos[0].y) * (pos[0].x - pos[1].x)) *
               rd;
    if (!(rn < 0.f || rn > 1.f || sn < 0.f || sn > 1.f))
      center = pos[0] + rn * (pos[2] - pos[0]);
    float d[4];
    for (int i = 0; i < 4; i++)
      d[i] = (pos[i] - center).mag();
    for (int i = 0; i < 4; i++) {
      float q = d[i] == 0.0f ? 1.0f : (d[i] + d[(i + 2) & 3]) / d[(i + 2) & 3];
      di.uv[i] *= q;
      di.w[i] *= q;
      di.pos[i] = {(pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f,
                   ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};
    }
    di.mode = nDecalMode;
    vLayers[nTargetLayer].vecDecalInstance.push_back(di);
  }
}

void PixelGameEngine::DrawWarpedDecal(olc::Decal *decal, const olc::vf2d *pos,
                                      const olc::Pixel &tint) {

  DecalInstance di;
  di.points = 4;
  di.decal = decal;
  di.tint = {tint, tint, tint, tint};
  di.w = {1, 1, 1, 1};
  di.pos.resize(4);
  di.uv = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};
  olc::vf2d center;
  float rd = ((pos[2].x - pos[0].x) * (pos[3].y - pos[1].y) -
              (pos[3].x - pos[1].x) * (pos[2].y - pos[0].y));
  if (rd != 0) {
    rd = 1.0f / rd;
    float rn = ((pos[3].x - pos[1].x) * (pos[0].y - pos[1].y) -
                (pos[3].y - pos[1].y) * (pos[0].x - pos[1].x)) *
               rd;
    float sn = ((pos[2].x - pos[0].x) * (pos[0].y - pos[1].y) -
                (pos[2].y - pos[0].y) * (pos[0].x - pos[1].x)) *
               rd;
    if (!(rn < 0.f || rn > 1.f || sn < 0.f || sn > 1.f))
      center = pos[0] + rn * (pos[2] - pos[0]);
    float d[4];
    for (int i = 0; i < 4; i++)
      d[i] = (pos[i] - center).mag();
    for (int i = 0; i < 4; i++) {
      float q = d[i] == 0.0f ? 1.0f : (d[i] + d[(i + 2) & 3]) / d[(i + 2) & 3];
      di.uv[i] *= q;
      di.w[i] *= q;
      di.pos[i] = {(pos[i].x * vInvScreenSize.x) * 2.0f - 1.0f,
                   ((pos[i].y * vInvScreenSize.y) * 2.0f - 1.0f) * -1.0f};
    }
    di.mode = nDecalMode;
    vLayers[nTargetLayer].vecDecalInstance.push_back(di);
  }
}

void PixelGameEngine::DrawWarpedDecal(olc::Decal *decal,
                                      const std::array<olc::vf2d, 4> &pos,
                                      const olc::Pixel &tint) {
  DrawWarpedDecal(decal, pos.data(), tint);
}

void PixelGameEngine::DrawWarpedDecal(olc::Decal *decal,
                                      const olc::vf2d (&pos)[4],
                                      const olc::Pixel &tint) {
  DrawWarpedDecal(decal, &pos[0], tint);
}

void PixelGameEngine::DrawPartialWarpedDecal(
    olc::Decal *decal, const std::array<olc::vf2d, 4> &pos,
    const olc::vf2d &source_pos, const olc::vf2d &source_size,
    const olc::Pixel &tint) {
  DrawPartialWarpedDecal(decal, pos.data(), source_pos, source_size, tint);
}

void PixelGameEngine::DrawPartialWarpedDecal(olc::Decal *decal,
                                             const olc::vf2d (&pos)[4],
                                             const olc::vf2d &source_pos,
                                             const olc::vf2d &source_size,
                                             const olc::Pixel &tint) {
  DrawPartialWarpedDecal(decal, &pos[0], source_pos, source_size, tint);
}

void PixelGameEngine::DrawStringDecal(const olc::vf2d &pos,
                                      const std::string &sText, const Pixel col,
                                      const olc::vf2d &scale) {
  olc::vf2d spos = {0.0f, 0.0f};
  for (auto c : sText) {
    if (c == '\n') {
      spos.x = 0;
      spos.y += 8.0f * scale.y;
    } else {
      int32_t ox = (c - 32) % 16;
      int32_t oy = (c - 32) / 16;
      DrawPartialDecal(pos + spos, fontDecal,
                       {float(ox) * 8.0f, float(oy) * 8.0f}, {8.0f, 8.0f},
                       scale, col);
      spos.x += 8.0f * scale.x;
    }
  }
}

void PixelGameEngine::DrawStringPropDecal(const olc::vf2d &pos,
                                          const std::string &sText,
                                          const Pixel col,
                                          const olc::vf2d &scale) {
  olc::vf2d spos = {0.0f, 0.0f};
  for (auto c : sText) {
    if (c == '\n') {
      spos.x = 0;
      spos.y += 8.0f * scale.y;
    } else {
      int32_t ox = (c - 32) % 16;
      int32_t oy = (c - 32) / 16;
      DrawPartialDecal(
          pos + spos, fontDecal,
          {float(ox) * 8.0f + float(vFontSpacing[c - 32].x), float(oy) * 8.0f},
          {float(vFontSpacing[c - 32].y), 8.0f}, scale, col);
      spos.x += float(vFontSpacing[c - 32].y) * scale.x;
    }
  }
}

olc::vi2d PixelGameEngine::GetTextSize(const std::string &s) {
  olc::vi2d size = {0, 1};
  olc::vi2d pos = {0, 1};
  for (auto c : s) {
    if (c == '\n') {
      pos.y++;
      pos.x = 0;
    } else
      pos.x++;
    size.x = std::max(size.x, pos.x);
    size.y = std::max(size.y, pos.y);
  }
  return size * 8;
}

void PixelGameEngine::DrawString(const olc::vi2d &pos, const std::string &sText,
                                 Pixel col, uint32_t scale) {
  DrawString(pos.x, pos.y, sText, col, scale);
}

void PixelGameEngine::DrawString(int32_t x, int32_t y, const std::string &sText,
                                 Pixel col, uint32_t scale) {
  int32_t sx = 0;
  int32_t sy = 0;
  Pixel::Mode m = nPixelMode;

  if (m != Pixel::CUSTOM) {
    if (col.a != 255)
      SetPixelMode(Pixel::ALPHA);
    else
      SetPixelMode(Pixel::MASK);
  }
  for (auto c : sText) {
    if (c == '\n') {
      sx = 0;
      sy += 8 * scale;
    } else {
      int32_t ox = (c - 32) % 16;
      int32_t oy = (c - 32) / 16;

      if (scale > 1) {
        for (uint32_t i = 0; i < 8; i++)
          for (uint32_t j = 0; j < 8; j++)
            if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
              for (uint32_t is = 0; is < scale; is++)
                for (uint32_t js = 0; js < scale; js++)
                  Draw(x + sx + (i * scale) + is, y + sy + (j * scale) + js,
                       col);
      } else {
        for (uint32_t i = 0; i < 8; i++)
          for (uint32_t j = 0; j < 8; j++)
            if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
              Draw(x + sx + i, y + sy + j, col);
      }
      sx += 8 * scale;
    }
  }
  SetPixelMode(m);
}

olc::vi2d PixelGameEngine::GetTextSizeProp(const std::string &s) {
  olc::vi2d size = {0, 1};
  olc::vi2d pos = {0, 1};
  for (auto c : s) {
    if (c == '\n') {
      pos.y += 1;
      pos.x = 0;
    } else
      pos.x += vFontSpacing[c - 32].y;
    size.x = std::max(size.x, pos.x);
    size.y = std::max(size.y, pos.y);
  }

  size.y *= 8;
  return size;
}

void PixelGameEngine::DrawStringProp(const olc::vi2d &pos,
                                     const std::string &sText, Pixel col,
                                     uint32_t scale) {
  DrawStringProp(pos.x, pos.y, sText, col, scale);
}

void PixelGameEngine::DrawStringProp(int32_t x, int32_t y,
                                     const std::string &sText, Pixel col,
                                     uint32_t scale) {
  int32_t sx = 0;
  int32_t sy = 0;
  Pixel::Mode m = nPixelMode;

  if (m != Pixel::CUSTOM) {
    if (col.a != 255)
      SetPixelMode(Pixel::ALPHA);
    else
      SetPixelMode(Pixel::MASK);
  }
  for (auto c : sText) {
    if (c == '\n') {
      sx = 0;
      sy += 8 * scale;
    } else {
      int32_t ox = (c - 32) % 16;
      int32_t oy = (c - 32) / 16;

      if (scale > 1) {
        for (int32_t i = 0; i < vFontSpacing[c - 32].y; i++)
          for (int32_t j = 0; j < 8; j++)
            if (fontSprite
                    ->GetPixel(i + ox * 8 + vFontSpacing[c - 32].x, j + oy * 8)
                    .r > 0)
              for (int32_t is = 0; is < int(scale); is++)
                for (int32_t js = 0; js < int(scale); js++)
                  Draw(x + sx + (i * scale) + is, y + sy + (j * scale) + js,
                       col);
      } else {
        for (int32_t i = 0; i < vFontSpacing[c - 32].y; i++)
          for (int32_t j = 0; j < 8; j++)
            if (fontSprite
                    ->GetPixel(i + ox * 8 + vFontSpacing[c - 32].x, j + oy * 8)
                    .r > 0)
              Draw(x + sx + i, y + sy + j, col);
      }
      sx += vFontSpacing[c - 32].y * scale;
    }
  }
  SetPixelMode(m);
}

void PixelGameEngine::SetPixelMode(Pixel::Mode m) { nPixelMode = m; }

Pixel::Mode PixelGameEngine::GetPixelMode() { return nPixelMode; }

void PixelGameEngine::SetPixelMode(
    std::function<olc::Pixel(const int x, const int y, const olc::Pixel &,
                             const olc::Pixel &)>
        pixelMode) {
  funcPixelMode = pixelMode;
  nPixelMode = Pixel::Mode::CUSTOM;
}

void PixelGameEngine::SetPixelBlend(float fBlend) {
  fBlendFactor = fBlend;
  if (fBlendFactor < 0.0f)
    fBlendFactor = 0.0f;
  if (fBlendFactor > 1.0f)
    fBlendFactor = 1.0f;
}

bool PixelGameEngine::OnUserCreate() { return false; }

bool PixelGameEngine::OnUserUpdate(float fElapsedTime) {
  (void)(fElapsedTime);
  return false;
}

bool PixelGameEngine::OnUserDestroy() { return true; }

void PixelGameEngine::olc_UpdateViewport() {
  int32_t ww = vScreenSize.x * vPixelSize.x;
  int32_t wh = vScreenSize.y * vPixelSize.y;
  float wasp = (float)ww / (float)wh;

  if (bPixelCohesion) {
    vScreenPixelSize = (vWindowSize / vScreenSize);
    vViewSize = (vWindowSize / vScreenSize) * vScreenSize;
  } else {
    vViewSize.x = (int32_t)vWindowSize.x;
    vViewSize.y = (int32_t)((float)vViewSize.x / wasp);

    if (vViewSize.y > vWindowSize.y) {
      vViewSize.y = vWindowSize.y;
      vViewSize.x = (int32_t)((float)vViewSize.y * wasp);
    }
  }

  vViewPos = (vWindowSize - vViewSize) / 2;
}

void PixelGameEngine::olc_UpdateWindowSize(int32_t x, int32_t y) {
  vWindowSize = {x, y};
  olc_UpdateViewport();
}

void PixelGameEngine::olc_UpdateMouseWheel(int32_t delta) {
  nMouseWheelDeltaCache += delta;
}

void PixelGameEngine::olc_UpdateMouse(int32_t x, int32_t y) {

  bHasMouseFocus = true;
  vMouseWindowPos = {x, y};

  x -= vViewPos.x;
  y -= vViewPos.y;
  vMousePosCache.x =
      (int32_t)(((float)x / (float)(vWindowSize.x - (vViewPos.x * 2)) *
                 (float)vScreenSize.x));
  vMousePosCache.y =
      (int32_t)(((float)y / (float)(vWindowSize.y - (vViewPos.y * 2)) *
                 (float)vScreenSize.y));
  if (vMousePosCache.x >= (int32_t)vScreenSize.x)
    vMousePosCache.x = vScreenSize.x - 1;
  if (vMousePosCache.y >= (int32_t)vScreenSize.y)
    vMousePosCache.y = vScreenSize.y - 1;
  if (vMousePosCache.x < 0)
    vMousePosCache.x = 0;
  if (vMousePosCache.y < 0)
    vMousePosCache.y = 0;
}

void PixelGameEngine::olc_UpdateMouseState(int32_t button, bool state) {
  pMouseNewState[button] = state;
}

void PixelGameEngine::olc_UpdateKeyState(int32_t key, bool state) {
  pKeyNewState[key] = state;
}

void PixelGameEngine::olc_UpdateMouseFocus(bool state) {
  bHasMouseFocus = state;
}

void PixelGameEngine::olc_UpdateKeyFocus(bool state) { bHasInputFocus = state; }

void PixelGameEngine::olc_Reanimate() { bAtomActive = true; }

bool PixelGameEngine::olc_IsRunning() { return bAtomActive; }

void PixelGameEngine::olc_Terminate() { bAtomActive = false; }

void PixelGameEngine::EngineThread() {

  if (platform->ThreadStartUp() == olc::FAIL)
    return;

  olc_PrepareEngine();

  for (auto &ext : vExtensions)
    ext->OnBeforeUserCreate();
  if (!OnUserCreate())
    bAtomActive = false;
  for (auto &ext : vExtensions)
    ext->OnAfterUserCreate();

  while (bAtomActive) {

    while (bAtomActive) {
      olc_CoreUpdate();
    }

    if (!OnUserDestroy()) {

      bAtomActive = true;
    }
  }

  platform->ThreadCleanUp();
}

void PixelGameEngine::olc_PrepareEngine() {

  if (platform->CreateGraphics(bFullScreen, bEnableVSYNC, vViewPos,
                               vViewSize) == olc::FAIL)
    return;

  olc_ConstructFontSheet();

  CreateLayer();
  vLayers[0].bUpdate = true;
  vLayers[0].bShow = true;
  SetDrawTarget(nullptr);

  m_tp1 = std::chrono::system_clock::now();
  m_tp2 = std::chrono::system_clock::now();
}

void PixelGameEngine::olc_CoreUpdate() {

  m_tp2 = std::chrono::system_clock::now();
  std::chrono::duration<float> elapsedTime = m_tp2 - m_tp1;
  m_tp1 = m_tp2;

  float fElapsedTime = elapsedTime.count();
  fLastElapsed = fElapsedTime;

  platform->HandleSystemEvent();

  auto ScanHardware = [&](HWButton *pKeys, bool *pStateOld, bool *pStateNew,
                          uint32_t nKeyCount) {
    for (uint32_t i = 0; i < nKeyCount; i++) {
      pKeys[i].bPressed = false;
      pKeys[i].bReleased = false;
      if (pStateNew[i] != pStateOld[i]) {
        if (pStateNew[i]) {
          pKeys[i].bPressed = !pKeys[i].bHeld;
          pKeys[i].bHeld = true;
        } else {
          pKeys[i].bReleased = true;
          pKeys[i].bHeld = false;
        }
      }
      pStateOld[i] = pStateNew[i];
    }
  };

  ScanHardware(pKeyboardState, pKeyOldState, pKeyNewState, 256);
  ScanHardware(pMouseState, pMouseOldState, pMouseNewState, nMouseButtons);

  vMousePos = vMousePosCache;
  nMouseWheelDelta = nMouseWheelDeltaCache;
  nMouseWheelDeltaCache = 0;

  for (auto &ext : vExtensions)
    ext->OnBeforeUserUpdate(fElapsedTime);
  if (!OnUserUpdate(fElapsedTime))
    bAtomActive = false;
  for (auto &ext : vExtensions)
    ext->OnAfterUserUpdate(fElapsedTime);

  renderer->UpdateViewport(vViewPos, vViewSize);
  renderer->ClearBuffer(olc::BLACK, true);

  vLayers[0].bUpdate = true;
  vLayers[0].bShow = true;
  SetDecalMode(DecalMode::NORMAL);
  renderer->PrepareDrawing();

  for (auto layer = vLayers.rbegin(); layer != vLayers.rend(); ++layer) {
    if (layer->bShow) {
      if (layer->funcHook == nullptr) {
        renderer->ApplyTexture(layer->nResID);
        if (layer->bUpdate) {
          renderer->UpdateTexture(layer->nResID, layer->pDrawTarget);
          layer->bUpdate = false;
        }

        renderer->DrawLayerQuad(layer->vOffset, layer->vScale, layer->tint);

        for (auto &decal : layer->vecDecalInstance)
          renderer->DrawDecal(decal);
        layer->vecDecalInstance.clear();
      } else {

        layer->funcHook();
      }
    }
  }

  renderer->DisplayFrame();

  fFrameTimer += fElapsedTime;
  nFrameCount++;
  if (fFrameTimer >= 1.0f) {
    nLastFPS = nFrameCount;
    fFrameTimer -= 1.0f;
    std::string sTitle = "OneLoneCoder.com - Pixel Game Engine - " + sAppName +
                         " - FPS: " + std::to_string(nFrameCount);
    platform->SetWindowTitle(sTitle);
    nFrameCount = 0;
  }
}

void PixelGameEngine::olc_ConstructFontSheet() {
  std::string data;
  data += "?Q`0001oOch0o01o@F40o0<AGD4090LAGD<090@A7ch0?00O7Q`0600>00000000";
  data += "O000000nOT0063Qo4d8>?7a14Gno94AA4gno94AaOT0>o3`oO400o7QN00000400";
  data += "Of80001oOg<7O7moBGT7O7lABET024@aBEd714AiOdl717a_=TH013Q>00000000";
  data += "720D000V?V5oB3Q_HdUoE7a9@DdDE4A9@DmoE4A;Hg]oM4Aj8S4D84@`00000000";
  data += "OaPT1000Oa`^13P1@AI[?g`1@A=[OdAoHgljA4Ao?WlBA7l1710007l100000000";
  data += "ObM6000oOfMV?3QoBDD`O7a0BDDH@5A0BDD<@5A0BGeVO5ao@CQR?5Po00000000";
  data += "Oc``000?Ogij70PO2D]??0Ph2DUM@7i`2DTg@7lh2GUj?0TO0C1870T?00000000";
  data += "70<4001o?P<7?1QoHg43O;`h@GT0@:@LB@d0>:@hN@L0@?aoN@<0O7ao0000?000";
  data += "OcH0001SOglLA7mg24TnK7ln24US>0PL24U140PnOgl0>7QgOcH0K71S0000A000";
  data += "00H00000@Dm1S007@DUSg00?OdTnH7YhOfTL<7Yh@Cl0700?@Ah0300700000000";
  data += "<008001QL00ZA41a@6HnI<1i@FHLM81M@@0LG81?O`0nC?Y7?`0ZA7Y300080000";
  data += "O`082000Oh0827mo6>Hn?Wmo?6HnMb11MP08@C11H`08@FP0@@0004@000000000";
  data += "00P00001Oab00003OcKP0006@6=PMgl<@440MglH@000000`@000001P00000000";
  data += "Ob@8@@00Ob@8@Ga13R@8Mga172@8?PAo3R@827QoOb@820@0O`0007`0000007P0";
  data += "O`000P08Od400g`<3V=P0G`673IP0`@3>1`00P@6O`P00g`<O`000GP800000000";
  data += "?P9PL020O`<`N3R0@E4HC7b0@ET<ATB0@@l6C4B0O`H3N7b0?P01L3R000000020";

  fontSprite = new olc::Sprite(128, 48);
  int px = 0, py = 0;
  for (size_t b = 0; b < 1024; b += 4) {
    uint32_t sym1 = (uint32_t)data[b + 0] - 48;
    uint32_t sym2 = (uint32_t)data[b + 1] - 48;
    uint32_t sym3 = (uint32_t)data[b + 2] - 48;
    uint32_t sym4 = (uint32_t)data[b + 3] - 48;
    uint32_t r = sym1 << 18 | sym2 << 12 | sym3 << 6 | sym4;

    for (int i = 0; i < 24; i++) {
      int k = r & (1 << i) ? 255 : 0;
      fontSprite->SetPixel(px, py, olc::Pixel(k, k, k, k));
      if (++py == 48) {
        px++;
        py = 0;
      }
    }
  }

  fontDecal = new olc::Decal(fontSprite);

  constexpr std::array<uint8_t, 96> vSpacing = {{
      0x03, 0x25, 0x16, 0x08, 0x07, 0x08, 0x08, 0x04, 0x15, 0x15, 0x08, 0x07,
      0x15, 0x07, 0x24, 0x08, 0x08, 0x17, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
      0x08, 0x08, 0x24, 0x15, 0x06, 0x07, 0x16, 0x17, 0x08, 0x08, 0x08, 0x08,
      0x08, 0x08, 0x08, 0x08, 0x08, 0x17, 0x08, 0x08, 0x17, 0x08, 0x08, 0x08,
      0x08, 0x08, 0x08, 0x08, 0x17, 0x08, 0x08, 0x08, 0x08, 0x17, 0x08, 0x15,
      0x08, 0x15, 0x08, 0x08, 0x24, 0x18, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
      0x17, 0x33, 0x17, 0x17, 0x33, 0x18, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
      0x07, 0x17, 0x17, 0x18, 0x18, 0x17, 0x17, 0x07, 0x33, 0x07, 0x08, 0x00,
  }};

  for (auto c : vSpacing)
    vFontSpacing.push_back({c >> 4, c & 15});
}

void PixelGameEngine::pgex_Register(olc::PGEX *pgex) {
  if (std::find(vExtensions.begin(), vExtensions.end(), pgex) ==
      vExtensions.end())
    vExtensions.push_back(pgex);
}

PGEX::PGEX(bool bHook) {
  if (bHook)
    pge->pgex_Register(this);
}
void PGEX::OnBeforeUserCreate() {}
void PGEX::OnAfterUserCreate() {}
void PGEX::OnBeforeUserUpdate(float &fElapsedTime) {}
void PGEX::OnAfterUserUpdate(float fElapsedTime) {}

std::atomic<bool> PixelGameEngine::bAtomActive{false};
olc::PixelGameEngine *olc::PGEX::pge = nullptr;
olc::PixelGameEngine *olc::Platform::ptrPGE = nullptr;
olc::PixelGameEngine *olc::Renderer::ptrPGE = nullptr;
std::unique_ptr<ImageLoader> olc::Sprite::loader = nullptr;
}; // namespace olc
#pragma endregion

#pragma region renderer_ogl10
#include <GL/gl.h>

namespace X11 {
#include <GL/glx.h>
}
typedef int(glSwapInterval_t)(X11::Display *dpy, X11::GLXDrawable drawable,
                              int interval);
static glSwapInterval_t *glSwapIntervalEXT;
typedef X11::GLXContext glDeviceContext_t;
typedef X11::GLXContext glRenderContext_t;
namespace olc {
class Renderer_OGL10 : public olc::Renderer {
private:
  glDeviceContext_t glDeviceContext = 0;
  glRenderContext_t glRenderContext = 0;

  bool bSync = false;
  olc::DecalMode nDecalMode = olc::DecalMode(-1);

  X11::Display *olc_Display = nullptr;
  X11::Window *olc_Window = nullptr;
  X11::XVisualInfo *olc_VisualInfo = nullptr;

public:
  void PrepareDevice() override {}

  olc::rcode CreateDevice(std::vector<void *> params, bool bFullScreen,
                          bool bVSYNC) override {
    using namespace X11;

    olc_Display = (X11::Display *)(params[0]);
    olc_Window = (X11::Window *)(params[1]);
    olc_VisualInfo = (X11::XVisualInfo *)(params[2]);

    glDeviceContext =
        glXCreateContext(olc_Display, olc_VisualInfo, nullptr, GL_TRUE);
    glXMakeCurrent(olc_Display, *olc_Window, glDeviceContext);

    XWindowAttributes gwa;
    XGetWindowAttributes(olc_Display, *olc_Window, &gwa);
    glViewport(0, 0, gwa.width, gwa.height);

    glSwapIntervalEXT = nullptr;
    glSwapIntervalEXT = (glSwapInterval_t *)glXGetProcAddress(
        (unsigned char *)"glXSwapIntervalEXT");

    if (glSwapIntervalEXT == nullptr && !bVSYNC) {
      printf("NOTE: Could not disable VSYNC, glXSwapIntervalEXT() was not "
             "found!\n");
      printf(
          "      Don't worry though, things will still work, it's just the\n");
      printf("      frame rate will be capped to your monitors refresh rate - "
             "javidx9\n");
    }

    if (glSwapIntervalEXT != nullptr && !bVSYNC)
      glSwapIntervalEXT(olc_Display, *olc_Window, 0);
    glEnable(GL_TEXTURE_2D);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    return olc::rcode::OK;
  }

  olc::rcode DestroyDevice() override {

    glXMakeCurrent(olc_Display, None, NULL);
    glXDestroyContext(olc_Display, glDeviceContext);

    return olc::rcode::OK;
  }

  void DisplayFrame() override {

    X11::glXSwapBuffers(olc_Display, *olc_Window);
  }

  void PrepareDrawing() override {
    glEnable(GL_BLEND);
    nDecalMode = DecalMode::NORMAL;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }

  void SetDecalMode(const olc::DecalMode &mode) override {
    if (mode != nDecalMode) {
      switch (mode) {
      case olc::DecalMode::NORMAL:
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;
      case olc::DecalMode::ADDITIVE:
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        break;
      case olc::DecalMode::MULTIPLICATIVE:
        glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
        break;
      case olc::DecalMode::STENCIL:
        glBlendFunc(GL_ZERO, GL_SRC_ALPHA);
        break;
      case olc::DecalMode::ILLUMINATE:
        glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
        break;
      case olc::DecalMode::WIREFRAME:
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;
      }

      nDecalMode = mode;
    }
  }

  void DrawLayerQuad(const olc::vf2d &offset, const olc::vf2d &scale,
                     const olc::Pixel tint) override {
    glBegin(GL_QUADS);
    glColor4ub(tint.r, tint.g, tint.b, tint.a);
    glTexCoord2f(0.0f * scale.x + offset.x, 1.0f * scale.y + offset.y);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glTexCoord2f(0.0f * scale.x + offset.x, 0.0f * scale.y + offset.y);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0f * scale.x + offset.x, 0.0f * scale.y + offset.y);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0f * scale.x + offset.x, 1.0f * scale.y + offset.y);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
  }

  void DrawDecal(const olc::DecalInstance &decal) override {
    SetDecalMode(decal.mode);

    if (decal.decal == nullptr)
      glBindTexture(GL_TEXTURE_2D, 0);
    else
      glBindTexture(GL_TEXTURE_2D, decal.decal->id);

    if (nDecalMode == DecalMode::WIREFRAME)
      glBegin(GL_LINE_LOOP);
    else
      glBegin(GL_TRIANGLE_FAN);

    for (uint32_t n = 0; n < decal.points; n++) {
      glColor4ub(decal.tint[n].r, decal.tint[n].g, decal.tint[n].b,
                 decal.tint[n].a);
      glTexCoord4f(decal.uv[n].x, decal.uv[n].y, 0.0f, decal.w[n]);
      glVertex2f(decal.pos[n].x, decal.pos[n].y);
    }
    glEnd();
  }

  uint32_t CreateTexture(const uint32_t width, const uint32_t height,
                         const bool filtered, const bool clamp) override {
    (void)(width);
    (void)(height);
    uint32_t id = 0;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    if (filtered) {
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else {
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }

    if (clamp) {
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    } else {
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    return id;
  }

  uint32_t DeleteTexture(const uint32_t id) override {
    glDeleteTextures(1, &id);
    return id;
  }

  void UpdateTexture(uint32_t id, olc::Sprite *spr) override {
    (void)(id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, spr->width, spr->height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, spr->GetData());
  }

  void ReadTexture(uint32_t id, olc::Sprite *spr) override {
    glReadPixels(0, 0, spr->width, spr->height, GL_RGBA, GL_UNSIGNED_BYTE,
                 spr->GetData());
  }

  void ApplyTexture(uint32_t id) override { glBindTexture(GL_TEXTURE_2D, id); }

  void ClearBuffer(olc::Pixel p, bool bDepth) override {
    glClearColor(float(p.r) / 255.0f, float(p.g) / 255.0f, float(p.b) / 255.0f,
                 float(p.a) / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (bDepth)
      glClear(GL_DEPTH_BUFFER_BIT);
  }

  void UpdateViewport(const olc::vi2d &pos, const olc::vi2d &size) override {

    glViewport(pos.x, pos.y, size.x, size.y);
  }
};
} // namespace olc

#pragma endregion

#pragma region renderer_ogl33
#pragma endregion

#pragma region image_gdi
#pragma endregion

#pragma region image_libpng

#include <png.h>
namespace olc {
void pngReadStream(png_structp pngPtr, png_bytep data, png_size_t length) {
  png_voidp a = png_get_io_ptr(pngPtr);
  ((std::istream *)a)->read((char *)data, length);
}

class ImageLoader_LibPNG : public olc::ImageLoader {
public:
  ImageLoader_LibPNG() : ImageLoader() {}

  olc::rcode LoadImageResource(olc::Sprite *spr, const std::string &sImageFile,
                               olc::ResourcePack *pack) override {
    (void)(pack);

    spr->pColData.clear();

    png_structp png;
    png_infop info;

    auto loadPNG = [&]() {
      png_read_info(png, info);
      png_byte color_type;
      png_byte bit_depth;
      png_bytep *row_pointers;
      spr->width = png_get_image_width(png, info);
      spr->height = png_get_image_height(png, info);
      color_type = png_get_color_type(png, info);
      bit_depth = png_get_bit_depth(png, info);
      if (bit_depth == 16)
        png_set_strip_16(png);
      if (color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);
      if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);
      if (png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);
      if (color_type == PNG_COLOR_TYPE_RGB ||
          color_type == PNG_COLOR_TYPE_GRAY ||
          color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
      if (color_type == PNG_COLOR_TYPE_GRAY ||
          color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);
      png_read_update_info(png, info);
      row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * spr->height);
      for (int y = 0; y < spr->height; y++) {
        row_pointers[y] = (png_byte *)malloc(png_get_rowbytes(png, info));
      }
      png_read_image(png, row_pointers);

      spr->pColData.resize(spr->width * spr->height);

      for (int y = 0; y < spr->height; y++) {
        png_bytep row = row_pointers[y];
        for (int x = 0; x < spr->width; x++) {
          png_bytep px = &(row[x * 4]);
          spr->SetPixel(x, y, Pixel(px[0], px[1], px[2], px[3]));
        }
      }

      for (int y = 0; y < spr->height; y++)
        free(row_pointers[y]);
      free(row_pointers);
      png_destroy_read_struct(&png, &info, nullptr);
    };

    png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png)
      goto fail_load;

    info = png_create_info_struct(png);
    if (!info)
      goto fail_load;

    if (setjmp(png_jmpbuf(png)))
      goto fail_load;

    if (pack == nullptr) {
      FILE *f = fopen(sImageFile.c_str(), "rb");
      if (!f)
        return olc::rcode::NO_FILE;
      png_init_io(png, f);
      loadPNG();
      fclose(f);
    } else {
      ResourceBuffer rb = pack->GetFileBuffer(sImageFile);
      std::istream is(&rb);
      png_set_read_fn(png, (png_voidp)&is, pngReadStream);
      loadPNG();
    }

    return olc::rcode::OK;

  fail_load:
    spr->width = 0;
    spr->height = 0;
    spr->pColData.clear();
    return olc::rcode::FAIL;
  }

  olc::rcode SaveImageResource(olc::Sprite *spr,
                               const std::string &sImageFile) override {
    return olc::rcode::OK;
  }
};
} // namespace olc

#pragma endregion

#pragma region image_stb
#pragma endregion

#pragma region platform_windows
#pragma endregion

#pragma region platform_linux

namespace olc {
class Platform_Linux : public olc::Platform {
private:
  X11::Display *olc_Display = nullptr;
  X11::Window olc_WindowRoot;
  X11::Window olc_Window;
  X11::XVisualInfo *olc_VisualInfo;
  X11::Colormap olc_ColourMap;
  X11::XSetWindowAttributes olc_SetWindowAttribs;
public:
  virtual olc::rcode ApplicationStartUp() override { return olc::rcode::OK; }
  virtual olc::rcode ApplicationCleanUp() override {
    XDestroyWindow(olc_Display, olc_Window);
    return olc::rcode::OK;
  }

  virtual olc::rcode ThreadStartUp() override { return olc::rcode::OK; }

  virtual olc::rcode ThreadCleanUp() override {
    renderer->DestroyDevice();
    return olc::OK;
  }

  virtual olc::rcode CreateGraphics(bool bFullScreen, bool bEnableVSYNC,
                                    const olc::vi2d &vViewPos,
                                    const olc::vi2d &vViewSize) override {
    if (renderer->CreateDevice({olc_Display, &olc_Window, olc_VisualInfo},
                               bFullScreen, bEnableVSYNC) == olc::rcode::OK) {
      renderer->UpdateViewport(vViewPos, vViewSize);
      return olc::rcode::OK;
    } else
      return olc::rcode::FAIL;
  }

  virtual olc::rcode CreateWindowPane(const olc::vi2d &vWindowPos,
                                      olc::vi2d &vWindowSize,
                                      bool bFullScreen) override {
    using namespace X11;
    XInitThreads();

    olc_Display = XOpenDisplay(NULL);
    olc_WindowRoot = DefaultRootWindow(olc_Display);

    GLint olc_GLAttribs[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER,
                             None};
    olc_VisualInfo = glXChooseVisual(olc_Display, 0, olc_GLAttribs);
    olc_ColourMap = XCreateColormap(olc_Display, olc_WindowRoot,
                                    olc_VisualInfo->visual, AllocNone);
    olc_SetWindowAttribs.colormap = olc_ColourMap;

    olc_SetWindowAttribs.event_mask = ExposureMask | KeyPressMask |
                                      KeyReleaseMask | ButtonPressMask |
                                      ButtonReleaseMask | PointerMotionMask |
                                      FocusChangeMask | StructureNotifyMask;

    olc_Window =
        XCreateWindow(olc_Display, olc_WindowRoot, vWindowPos.x, vWindowPos.y,
                      vWindowSize.x, vWindowSize.y, 0, olc_VisualInfo->depth,
                      InputOutput, olc_VisualInfo->visual,
                      CWColormap | CWEventMask, &olc_SetWindowAttribs);

    Atom wmDelete = XInternAtom(olc_Display, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(olc_Display, olc_Window, &wmDelete, 1);

    XMapWindow(olc_Display, olc_Window);
    XStoreName(olc_Display, olc_Window, "OneLoneCoder.com - Pixel Game Engine");

    if (bFullScreen) {
      Atom wm_state;
      Atom fullscreen;
      wm_state = XInternAtom(olc_Display, "_NET_WM_STATE", False);
      fullscreen = XInternAtom(olc_Display, "_NET_WM_STATE_FULLSCREEN", False);
      XEvent xev{0};
      xev.type = ClientMessage;
      xev.xclient.window = olc_Window;
      xev.xclient.message_type = wm_state;
      xev.xclient.format = 32;
      xev.xclient.data.l[0] = (bFullScreen ? 1 : 0);
      xev.xclient.data.l[1] = fullscreen;
      xev.xclient.data.l[2] = 0;
      xev.xclient.data.l[3] = 0;
      XMapWindow(olc_Display, olc_Window);
      XSendEvent(olc_Display, DefaultRootWindow(olc_Display), False,
                 SubstructureRedirectMask | SubstructureNotifyMask, &xev);
      XFlush(olc_Display);
      XWindowAttributes gwa;
      XGetWindowAttributes(olc_Display, olc_Window, &gwa);
      vWindowSize.x = gwa.width;
      vWindowSize.y = gwa.height;
    }

    mapKeys[0x00] = Key::NONE;
    mapKeys[0x61] = Key::A;
    mapKeys[0x62] = Key::B;
    mapKeys[0x63] = Key::C;
    mapKeys[0x64] = Key::D;
    mapKeys[0x65] = Key::E;
    mapKeys[0x66] = Key::F;
    mapKeys[0x67] = Key::G;
    mapKeys[0x68] = Key::H;
    mapKeys[0x69] = Key::I;
    mapKeys[0x6A] = Key::J;
    mapKeys[0x6B] = Key::K;
    mapKeys[0x6C] = Key::L;
    mapKeys[0x6D] = Key::M;
    mapKeys[0x6E] = Key::N;
    mapKeys[0x6F] = Key::O;
    mapKeys[0x70] = Key::P;
    mapKeys[0x71] = Key::Q;
    mapKeys[0x72] = Key::R;
    mapKeys[0x73] = Key::S;
    mapKeys[0x74] = Key::T;
    mapKeys[0x75] = Key::U;
    mapKeys[0x76] = Key::V;
    mapKeys[0x77] = Key::W;
    mapKeys[0x78] = Key::X;
    mapKeys[0x79] = Key::Y;
    mapKeys[0x7A] = Key::Z;

    mapKeys[XK_F1] = Key::F1;
    mapKeys[XK_F2] = Key::F2;
    mapKeys[XK_F3] = Key::F3;
    mapKeys[XK_F4] = Key::F4;
    mapKeys[XK_F5] = Key::F5;
    mapKeys[XK_F6] = Key::F6;
    mapKeys[XK_F7] = Key::F7;
    mapKeys[XK_F8] = Key::F8;
    mapKeys[XK_F9] = Key::F9;
    mapKeys[XK_F10] = Key::F10;
    mapKeys[XK_F11] = Key::F11;
    mapKeys[XK_F12] = Key::F12;

    mapKeys[XK_Down] = Key::DOWN;
    mapKeys[XK_Left] = Key::LEFT;
    mapKeys[XK_Right] = Key::RIGHT;
    mapKeys[XK_Up] = Key::UP;
    mapKeys[XK_KP_Enter] = Key::ENTER;
    mapKeys[XK_Return] = Key::ENTER;

    mapKeys[XK_BackSpace] = Key::BACK;
    mapKeys[XK_Escape] = Key::ESCAPE;
    mapKeys[XK_Linefeed] = Key::ENTER;
    mapKeys[XK_Pause] = Key::PAUSE;
    mapKeys[XK_Scroll_Lock] = Key::SCROLL;
    mapKeys[XK_Tab] = Key::TAB;
    mapKeys[XK_Delete] = Key::DEL;
    mapKeys[XK_Home] = Key::HOME;
    mapKeys[XK_End] = Key::END;
    mapKeys[XK_Page_Up] = Key::PGUP;
    mapKeys[XK_Page_Down] = Key::PGDN;
    mapKeys[XK_Insert] = Key::INS;
    mapKeys[XK_Shift_L] = Key::SHIFT;
    mapKeys[XK_Shift_R] = Key::SHIFT;
    mapKeys[XK_Control_L] = Key::CTRL;
    mapKeys[XK_Control_R] = Key::CTRL;
    mapKeys[XK_space] = Key::SPACE;
    mapKeys[XK_period] = Key::PERIOD;

    mapKeys[XK_0] = Key::K0;
    mapKeys[XK_1] = Key::K1;
    mapKeys[XK_2] = Key::K2;
    mapKeys[XK_3] = Key::K3;
    mapKeys[XK_4] = Key::K4;
    mapKeys[XK_5] = Key::K5;
    mapKeys[XK_6] = Key::K6;
    mapKeys[XK_7] = Key::K7;
    mapKeys[XK_8] = Key::K8;
    mapKeys[XK_9] = Key::K9;

    mapKeys[XK_KP_0] = Key::NP0;
    mapKeys[XK_KP_1] = Key::NP1;
    mapKeys[XK_KP_2] = Key::NP2;
    mapKeys[XK_KP_3] = Key::NP3;
    mapKeys[XK_KP_4] = Key::NP4;
    mapKeys[XK_KP_5] = Key::NP5;
    mapKeys[XK_KP_6] = Key::NP6;
    mapKeys[XK_KP_7] = Key::NP7;
    mapKeys[XK_KP_8] = Key::NP8;
    mapKeys[XK_KP_9] = Key::NP9;
    mapKeys[XK_KP_Multiply] = Key::NP_MUL;
    mapKeys[XK_KP_Add] = Key::NP_ADD;
    mapKeys[XK_KP_Divide] = Key::NP_DIV;
    mapKeys[XK_KP_Subtract] = Key::NP_SUB;
    mapKeys[XK_KP_Decimal] = Key::NP_DECIMAL;

    mapKeys[XK_semicolon] = Key::OEM_1;
    mapKeys[XK_slash] = Key::OEM_2;
    mapKeys[XK_asciitilde] = Key::OEM_3;
    mapKeys[XK_bracketleft] = Key::OEM_4;
    mapKeys[XK_backslash] = Key::OEM_5;
    mapKeys[XK_bracketright] = Key::OEM_6;
    mapKeys[XK_apostrophe] = Key::OEM_7;

    mapKeys[XK_numbersign] = Key::OEM_8;

    mapKeys[XK_equal] = Key::EQUALS;
    mapKeys[XK_comma] = Key::COMMA;
    mapKeys[XK_minus] = Key::MINUS;

    mapKeys[XK_Caps_Lock] = Key::CAPS_LOCK;

    return olc::OK;
  }

  virtual olc::rcode SetWindowTitle(const std::string &s) override {
    X11::XStoreName(olc_Display, olc_Window, s.c_str());
    return olc::OK;
  }

  virtual olc::rcode StartSystemEventLoop() override { return olc::OK; }

  virtual olc::rcode HandleSystemEvent() override {
    using namespace X11;

    XEvent xev;
    while (XPending(olc_Display)) {
      XNextEvent(olc_Display, &xev);
      if (xev.type == Expose) {
        XWindowAttributes gwa;
        XGetWindowAttributes(olc_Display, olc_Window, &gwa);
        ptrPGE->olc_UpdateWindowSize(gwa.width, gwa.height);
      } else if (xev.type == ConfigureNotify) {
        XConfigureEvent xce = xev.xconfigure;
        ptrPGE->olc_UpdateWindowSize(xce.width, xce.height);
      } else if (xev.type == KeyPress) {
        KeySym sym = XLookupKeysym(&xev.xkey, 0);
        ptrPGE->olc_UpdateKeyState(mapKeys[sym], true);
        XKeyEvent *e = (XKeyEvent *)&xev;
        XLookupString(e, NULL, 0, &sym, NULL);
        ptrPGE->olc_UpdateKeyState(mapKeys[sym], true);
      } else if (xev.type == KeyRelease) {
        KeySym sym = XLookupKeysym(&xev.xkey, 0);
        ptrPGE->olc_UpdateKeyState(mapKeys[sym], false);
        XKeyEvent *e = (XKeyEvent *)&xev;
        XLookupString(e, NULL, 0, &sym, NULL);
        ptrPGE->olc_UpdateKeyState(mapKeys[sym], false);
      } else if (xev.type == ButtonPress) {
        switch (xev.xbutton.button) {
        case 1:
          ptrPGE->olc_UpdateMouseState(0, true);
          break;
        case 2:
          ptrPGE->olc_UpdateMouseState(2, true);
          break;
        case 3:
          ptrPGE->olc_UpdateMouseState(1, true);
          break;
        case 4:
          ptrPGE->olc_UpdateMouseWheel(120);
          break;
        case 5:
          ptrPGE->olc_UpdateMouseWheel(-120);
          break;
        default:
          break;
        }
      } else if (xev.type == ButtonRelease) {
        switch (xev.xbutton.button) {
        case 1:
          ptrPGE->olc_UpdateMouseState(0, false);
          break;
        case 2:
          ptrPGE->olc_UpdateMouseState(2, false);
          break;
        case 3:
          ptrPGE->olc_UpdateMouseState(1, false);
          break;
        default:
          break;
        }
      } else if (xev.type == MotionNotify) {
        ptrPGE->olc_UpdateMouse(xev.xmotion.x, xev.xmotion.y);
      } else if (xev.type == FocusIn) {
        ptrPGE->olc_UpdateKeyFocus(true);
      } else if (xev.type == FocusOut) {
        ptrPGE->olc_UpdateKeyFocus(false);
      } else if (xev.type == ClientMessage) {
        ptrPGE->olc_Terminate();
      }
    }
    return olc::OK;
  }
};
} // namespace olc

#pragma endregion

#pragma region platform_glut
#pragma endregion

#pragma region platform_emscripten
#pragma endregion

#pragma region pge_config
namespace olc {
void PixelGameEngine::olc_ConfigureSystem() {

  olc::Sprite::loader = std::make_unique<olc::ImageLoader_LibPNG>();
  platform = std::make_unique<olc::Platform_Linux>();
  renderer = std::make_unique<olc::Renderer_OGL10>();
  platform->ptrPGE = this;
  renderer->ptrPGE = this;
}
} // namespace olc

#pragma endregion
