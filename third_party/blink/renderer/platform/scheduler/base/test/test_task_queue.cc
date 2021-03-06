// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/scheduler/base/test/test_task_queue.h"

#include "third_party/blink/renderer/platform/scheduler/base/task_queue_impl.h"

namespace base {
namespace sequence_manager {

TestTaskQueue::TestTaskQueue(std::unique_ptr<internal::TaskQueueImpl> impl,
                             const TaskQueue::Spec& spec)
    : TaskQueue(std::move(impl), spec), weak_factory_(this) {}

TestTaskQueue::~TestTaskQueue() = default;

WeakPtr<TestTaskQueue> TestTaskQueue::GetWeakPtr() {
  return weak_factory_.GetWeakPtr();
}

}  // namespace sequence_manager
}  // namespace base
