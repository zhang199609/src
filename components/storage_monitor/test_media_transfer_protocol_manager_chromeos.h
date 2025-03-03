// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_STORAGE_MONITOR_TEST_MEDIA_TRANSFER_PROTOCOL_MANAGER_CHROMEOS_H_
#define COMPONENTS_STORAGE_MONITOR_TEST_MEDIA_TRANSFER_PROTOCOL_MANAGER_CHROMEOS_H_

#include <stddef.h>
#include <stdint.h>

#include <string>

#include "base/macros.h"
#include "mojo/public/cpp/bindings/binding_set.h"
#include "services/device/public/mojom/mtp_manager.mojom.h"

namespace storage_monitor {

// A dummy MediaTransferProtocolManager implementation.
class TestMediaTransferProtocolManagerChromeOS
    : public device::mojom::MtpManager {
 public:
  static TestMediaTransferProtocolManagerChromeOS* GetFakeMtpManager();
  TestMediaTransferProtocolManagerChromeOS();
  ~TestMediaTransferProtocolManagerChromeOS() override;

  void AddBinding(device::mojom::MtpManagerRequest request);

 private:
  // device::mojom::MtpManager implementation.
  void EnumerateStoragesAndSetClient(
      device::mojom::MtpManagerClientAssociatedPtrInfo client,
      EnumerateStoragesAndSetClientCallback callback) override;
  void GetStorageInfo(const std::string& storage_name,
                      GetStorageInfoCallback callback) override;
  void GetStorageInfoFromDevice(
      const std::string& storage_name,
      GetStorageInfoFromDeviceCallback callback) override;
  void OpenStorage(const std::string& storage_name,
                   const std::string& mode,
                   OpenStorageCallback callback) override;
  void CloseStorage(const std::string& storage_handle,
                    CloseStorageCallback callback) override;
  void CreateDirectory(const std::string& storage_handle,
                       uint32_t parent_id,
                       const std::string& directory_name,
                       CreateDirectoryCallback callback) override;
  void ReadDirectory(const std::string& storage_handle,
                     uint32_t file_id,
                     uint64_t max_size,
                     ReadDirectoryCallback callback) override;
  void ReadFileChunk(const std::string& storage_handle,
                     uint32_t file_id,
                     uint32_t offset,
                     uint32_t count,
                     ReadFileChunkCallback callback) override;
  void GetFileInfo(const std::string& storage_handle,
                   uint32_t file_id,
                   GetFileInfoCallback callback) override;
  void RenameObject(const std::string& storage_handle,
                    uint32_t object_id,
                    const std::string& new_name,
                    RenameObjectCallback callback) override;
  void CopyFileFromLocal(const std::string& storage_handle,
                         int64_t source_file_descriptor,
                         uint32_t parent_id,
                         const std::string& file_name,
                         CopyFileFromLocalCallback callback) override;
  void DeleteObject(const std::string& storage_handle,
                    uint32_t object_id,
                    DeleteObjectCallback callback) override;

  mojo::BindingSet<device::mojom::MtpManager> bindings_;

  DISALLOW_COPY_AND_ASSIGN(TestMediaTransferProtocolManagerChromeOS);
};

}  // namespace storage_monitor

#endif  // COMPONENTS_STORAGE_MONITOR_TEST_MEDIA_TRANSFER_PROTOCOL_MANAGER_CHROMEOS_H_
