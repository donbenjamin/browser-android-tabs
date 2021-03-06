// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/sync/driver/data_type_controller.h"

#include "components/sync/base/data_type_histogram.h"
#include "components/sync/syncable/user_share.h"

namespace syncer {

DataTypeController::DataTypeController(ModelType type) : type_(type) {}

DataTypeController::~DataTypeController() {}

// static
bool DataTypeController::IsUnrecoverableResult(ConfigureResult result) {
  return (result == UNRECOVERABLE_ERROR);
}

// static
bool DataTypeController::IsSuccessfulResult(ConfigureResult result) {
  return (result == OK || result == OK_FIRST_RUN);
}

// static
std::string DataTypeController::StateToString(State state) {
  switch (state) {
    case NOT_RUNNING:
      return "Not Running";
    case MODEL_STARTING:
      return "Model Starting";
    case MODEL_LOADED:
      return "Model Loaded";
    case ASSOCIATING:
      return "Associating";
    case RUNNING:
      return "Running";
    case STOPPING:
      return "Stopping";
    case DISABLED:
      return "Disabled";
  }
  NOTREACHED();
  return "Invalid";
}

bool DataTypeController::ReadyForStart() const {
  return true;
}

bool DataTypeController::CalledOnValidThread() const {
  return sequence_checker_.CalledOnValidSequence();
}

}  // namespace syncer
