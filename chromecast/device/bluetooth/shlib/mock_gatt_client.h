// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMECAST_DEVICE_BLUETOOTH_SHLIB_MOCK_GATT_CLIENT_H_
#define CHROMECAST_DEVICE_BLUETOOTH_SHLIB_MOCK_GATT_CLIENT_H_

#include <vector>

#include "chromecast/device/bluetooth/shlib/gatt_client.h"
#include "testing/gmock/include/gmock/gmock.h"

namespace chromecast {
namespace bluetooth_v2_shlib {

class MockGattClient : public GattClient {
 public:
  MockGattClient();
  ~MockGattClient() override;
  MOCK_METHOD0(IsSupported, bool());
  MOCK_METHOD1(Connect, bool(const Addr&));
  void SetDelegate(Gatt::Client::Delegate* delegate) override {
    delegate_ = delegate;
  }
  MOCK_METHOD0(Enable, bool());
  MOCK_METHOD0(Disable, bool());
  MOCK_METHOD1(Disconnect, bool(const Addr&));
  MOCK_METHOD3(ReadCharacteristic,
               bool(const Addr&,
                    const Gatt::Characteristic&,
                    Gatt::Client::AuthReq));
  MOCK_METHOD5(WriteCharacteristic,
               bool(const Addr&,
                    const Gatt::Characteristic&,
                    Gatt::Client::AuthReq,
                    Gatt::WriteType,
                    const std::vector<uint8_t>&));
  MOCK_METHOD3(ReadDescriptor,
               bool(const Addr&,
                    const Gatt::Descriptor&,
                    Gatt::Client::AuthReq));
  MOCK_METHOD4(WriteDescriptor,
               bool(const Addr&,
                    const Gatt::Descriptor&,
                    Gatt::Client::AuthReq,
                    const std::vector<uint8_t>&));
  MOCK_METHOD3(SetCharacteristicNotification,
               bool(const Addr&, const Gatt::Characteristic&, bool));
  MOCK_METHOD1(ReadRemoteRssi, bool(const Addr&));
  MOCK_METHOD2(RequestMtu, bool(const Addr&, int mtu));
  MOCK_METHOD5(ConnectionParameterUpdate,
               bool(const Addr&, int, int, int, int));
  MOCK_METHOD1(GetServices, bool(const Addr&));

  Gatt::Client::Delegate* delegate() const { return delegate_; }

 private:
  Gatt::Client::Delegate* delegate_ = nullptr;
};

inline MockGattClient::MockGattClient() = default;
inline MockGattClient::~MockGattClient() = default;

}  // namespace bluetooth_v2_shlib
}  // namespace chromecast

#endif  // CHROMECAST_DEVICE_BLUETOOTH_SHLIB_MOCK_GATT_CLIENT_H_
