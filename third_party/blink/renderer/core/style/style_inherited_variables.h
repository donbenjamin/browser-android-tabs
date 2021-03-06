// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_STYLE_INHERITED_VARIABLES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_STYLE_INHERITED_VARIABLES_H_

#include "third_party/blink/renderer/core/css/css_value.h"
#include "third_party/blink/renderer/core/css/css_variable_data.h"
#include "third_party/blink/renderer/platform/wtf/forward.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/ref_counted.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string_hash.h"

namespace blink {

class StyleInheritedVariables : public RefCounted<StyleInheritedVariables> {
 public:
  static scoped_refptr<StyleInheritedVariables> Create() {
    return base::AdoptRef(new StyleInheritedVariables());
  }

  scoped_refptr<StyleInheritedVariables> Copy() {
    return base::AdoptRef(new StyleInheritedVariables(*this));
  }

  bool operator==(const StyleInheritedVariables& other) const;
  bool operator!=(const StyleInheritedVariables& other) const {
    return !(*this == other);
  }

  void SetVariable(const AtomicString& name,
                   scoped_refptr<CSSVariableData> value) {
    data_.Set(name, std::move(value));
  }
  CSSVariableData* GetVariable(const AtomicString& name) const;
  void RemoveVariable(const AtomicString&);

  void SetRegisteredVariable(const AtomicString&, const CSSValue*);
  const CSSValue* RegisteredVariable(const AtomicString&) const;

  // This map will contain null pointers if variables are invalid due to
  // cycles or referencing invalid variables without using a fallback.
  // Note that this method is slow as a new map is constructed.
  std::unique_ptr<HashMap<AtomicString, scoped_refptr<CSSVariableData>>>
  GetVariables() const;

 private:
  StyleInheritedVariables() : root_(nullptr) {}
  StyleInheritedVariables(StyleInheritedVariables& other);

  friend class CSSVariableResolver;

  HashMap<AtomicString, scoped_refptr<CSSVariableData>> data_;
  HashMap<AtomicString, Persistent<CSSValue>> registered_data_;
  scoped_refptr<StyleInheritedVariables> root_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_STYLE_INHERITED_VARIABLES_H_
