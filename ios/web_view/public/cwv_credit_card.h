// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_WEB_VIEW_PUBLIC_CWV_CREDIT_CARD_H_
#define IOS_WEB_VIEW_PUBLIC_CWV_CREDIT_CARD_H_

#import <UIKit/UIKit.h>

#import "cwv_export.h"

NS_ASSUME_NONNULL_BEGIN

CWV_EXPORT
// Represents a credit card for autofilling payment forms.
@interface CWVCreditCard : NSObject

// The full name of the card holder. e.g. "John Doe".
@property(nonatomic, copy, nullable) NSString* cardHolderFullName;
// The permanent account number of the card. e.g. "0123456789012345".
@property(nonatomic, copy, nullable) NSString* cardNumber;
// The network this card belongs to. e.g. "Visa", "Amex", "MasterCard".
// Inferred from |cardNumber|.
@property(nonatomic, copy, nullable, readonly) NSString* networkName;
// The image that represents the |networkName|.
@property(nonatomic, readonly) UIImage* networkIcon;
// The month this card expires on. e.g. "08".
@property(nonatomic, copy, nullable) NSString* expirationMonth;
// The year this card expires on. e.g. "2020".
@property(nonatomic, copy, nullable) NSString* expirationYear;
// The issuing bank of this card. "Chase", "Bank of America".
@property(nonatomic, copy, nullable, readonly) NSString* bankName;
// Storage type for this card. |YES| if this card is purely local, or a local
// copy of a remote card.
@property(nonatomic, readonly, getter=isSavedLocally) BOOL savedLocally;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif  // IOS_WEB_VIEW_PUBLIC_CWV_CREDIT_CARD_H_
