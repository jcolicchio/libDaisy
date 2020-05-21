#pragma once
#ifndef DSY_SPI_H
#define DSY_SPI_H

#include "daisy_core.h"

// # SPI
// TODO:
// - Add documentation
// - Add configuration
// - Add reception
// - Add IT
// - Add DMA

namespace daisy
{
class SpiHandle
{
    enum Periph
    {
        PERIPH_1,
        PERIPH_3,
        PERIPH_6,
    };

    enum Pin
    {
        PIN_CS,
        PIN_SCK,
        PIN_MOSI,
        PIN_MISO,
    };

    enum ChipSelect
    {
        CS_SOFT,
        CS_HARD_IN,
        CS_HARD_OUT,
    };

    enum ClockDivider
    {
        CLOCK_DIVIDE_2,
        CLOCK_DIVIDE_4,
        CLOCK_DIVIDE_8,
        CLOCK_DIVIDE_16,
        CLOCK_DIVIDE_32,
        CLOCK_DIVIDE_64,
        CLOCK_DIVIDE_128,
        CLOCK_DIVIDE_256,
    };

  public:
    SpiHandle() {}
    ~SpiHandle() {}

    void Init(Periph       periph,
              ChipSelect   chip_select,
              ClockDivider clock_divide,
              uint8_t       data_size);

    void BlockingTransmit(uint8_t *buff, size_t size);

  private:
};

} // namespace daisy

#endif