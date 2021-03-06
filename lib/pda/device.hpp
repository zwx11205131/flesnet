/**
 * @file
 * @author Dirk Hutter <hutter@compeng.uni-frankfurt.de>
 * @author Dominic Eschweiler<dominic.eschweiler@cern.ch>
 *
 */
#pragma once

#include <cstdint>
#include <cstdio>

typedef struct DeviceOperator_struct DeviceOperator;
typedef struct PciDevice_struct PciDevice;

namespace pda {
class device_operator;

/**
 * @class
 * @brief Represents a FLIB PCIe device
 **/
class device {
  friend class dma_buffer;

public:
  device(device_operator* device_operator, int32_t device_index);
  device(const uint8_t bus, const uint8_t device, const uint8_t function);
  ~device();

  uint16_t domain();

  /**
   * PCIe Bus-ID
   * @return uint8 Bus-ID
   **/
  uint8_t bus();

  /**
   * PCIe Slot-ID
   * @return uint8 Slot-ID
   **/
  uint8_t slot();

  /**
   * PCIe Function-ID
   * @return uint8 Function-ID
   **/
  uint8_t func();

  /**
   * PCIe max_payload_size
   * @return size_t max_payload_size
   **/
  size_t max_payload_size();

  /**
   * PCI-Device
   * @return PCI-Device-Pointer
   **/
  PciDevice* PDAPciDevice() { return (m_device); }

protected:
  device_operator* m_parent_dop;
  PciDevice* m_device;
};
} // namespace pda
