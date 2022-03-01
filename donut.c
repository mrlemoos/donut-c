int main()
{
  const float FIRST_ANGLE_BYTE_SET = 6.28;
  const float FIRST_ANGLE_INCREMENT = 0.07;

  const float SECOND_ANGLE_BYTE_SET = 6.28;
  const float SECOND_ANGLE_INCREMENT = 0.02;

  const int SLEEP_TIME = 30000;

  char b[1760];
  float z[1760];

  float shapeAxisX = 0;
  float shapeAxisY = 0;

  while (1 == 1)
  {
    memset(b, 32, 1760);
    memset(z, 0, 1760);

    for (float index = 0; index < FIRST_ANGLE_BYTE_SET; index += FIRST_ANGLE_INCREMENT)
    {
      for (float jndex = 0; jndex < SECOND_ANGLE_BYTE_SET; jndex += SECOND_ANGLE_INCREMENT)
      {
        float c = sin(index);
        float d = cos(jndex);
        float e = sin(shapeAxisX);
        float f = sin(jndex);
        float g = cos(shapeAxisX);
        float h = d + 2;
        float D = 1 / (c * h * e + f * g + 5);
        float l = cos(index);
        float m = cos(shapeAxisY);
        float n = sin(shapeAxisY);

        float t = c * h * g - f * e;

        int x = 40 + 30 * D * (l * h * m - t * n);
        int y = 12 + 15 * D * (l * h * n + t * m);
        int o = x + 80 * y;
        int appendIndex = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

        if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
        {
          z[o] = D;
          b[o] = ".,-~:;=!*#$@"[appendIndex > 0 ? appendIndex : 0];
        }
      }
    }
    print("\x1b[H");

    for (int index = 0; index < 1761; index++)
    {
      putchar(index % 80 ? b[index] : 10);
      shapeAxisX += 0.00004;
      shapeAxisY += 0.00002;
    }
    usleep(SLEEP_TIME);
  }

  return 0;
}
