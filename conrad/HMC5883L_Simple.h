// #include <stdint.h>
#ifndef HMC5883LSimple_h
#define HMC5883LSimple_h
#define COMPASS_I2C_ADDRESS 0x3C >> 1

#define COMPASS_CONFIG_REGISTER_A 0x00
#define COMPASS_CONFIG_REGISTER_B 0x01
#define COMPASS_MODE_REGISTER 0x02
#define COMPASS_DATA_REGISTER 0x03
#define COMPASS_DATA_CACHE_L1 0x88
#define COMPASS_DATA_CACHE_L2 0x89
#define COMPASS_DATA_CACHE_L3 0x90
#define COMPASS_CONSTANT 0x08

#define COMPASS_CONTINUOUS 0x00
#define COMPASS_SINGLE 0x01
#define COMPASS_IDLE 0x02

#define COMPASS_SCALE_088 0x00 << 2
#define COMPASS_SCALE_130 0x01 << 2
#define COMPASS_SCALE_190 0x02 << 2
#define COMPASS_SCALE_250 0x03 << 2
#define COMPASS_SCALE_400 0x04 << 2
#define COMPASS_SCALE_470 0x05 << 2
#define COMPASS_SCALE_560 0x06 << 2
#define COMPASS_SCALE_810 0x07 << 2

#define COMPASS_NORTH 0x00
#define COMPASS_SOUTH 0x01
#define COMPASS_WEST 0x02
#define COMPASS_EAST 0x03
#define COMPASS_UP 0x04
#define COMPASS_DOWN 0x05

#define COMPASS_HORIZONTAL_X_NORTH ((COMPASS_NORTH << 6) | (COMPASS_WEST << 3) | COMPASS_UP) << 5
#define COMPASS_HORIZONTAL_Y_NORTH ((COMPASS_EAST << 6) | (COMPASS_NORTH << 3) | COMPASS_UP) << 5
#define COMPASS_VERTICAL_X_EAST ((COMPASS_EAST << 6) | (COMPASS_UP << 3) | COMPASS_SOUTH) << 5
#define COMPASS_VERTICAL_Y_WEST ((COMPASS_UP << 6) | (COMPASS_WEST << 3) | COMPASS_SOUTH) << 5

class HMC5883L_Simple {
public:
  HMC5883L_Simple();
  void SetScale(int sampling_mode);
  void SetOrientation(int sampling_mode);
  void SetDeclination(int declination_degs, int declination_mins, char declination_dir);
  void SetSamplingMode(int sampling_mode);

  float GetHeadingDegrees();

protected:
  void Write(int address, int byte);
  uint8_t Read(int register_address, int buffer[], int length);

  struct MagnetometerSample {
    int X;
    int Y;
    int Z;
  };

  MagnetometerSample ReadAxes();

  int mode;
  float declination_offset_radians;

private:
  int i2c_address;
};
#endif
