//
//  BUConfigId.h
//  BlinkUp
//
//  Created by Brett Park on 2014-12-10.
//  Copyright (c) 2015 Electric Imp, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  Identifier of the device configuration session
 *
 *  The ConfigId is used as a unique token that represents a single configuration
 *  of a device. It is created by the Electric Imp servers and should only be
 *  used for a single configuration session. On subsequent configuration attempts
 *  (even on the same device) a new configId should be used.
 */
@interface BUConfigId : NSObject

/*!
 *  @brief  Block called when configuration has been retrieved
 *
 *  @param configId Will return this same object for easier access
 *  @param error    If not nil, the error that has occured
 */
  typedef void (^BUConfigIdCompletionHandler)(BUConfigId *_Nonnull configId, NSError *_Nullable error);

/*!
 *  @brief  Initialize using a new planId
 *
 *   If using Swift and want enumerated results, please use the Swift extension method
 *
 *  @param apiKey            The APIKey assigned to you from Electric Imp
 *  @param completionHandler Block called when the configuration id is
 *    retrieved from the Electric Imp server. If error is nil, then the configId
 *    has been succesfully activated.
 *
 *  @return ConfigId that may or may not be active
 */
- (nonnull instancetype)initWithApiKey:(nonnull NSString *)apiKey completionHandler:(nullable BUConfigIdCompletionHandler)completionHandler;

/*!
 *  @brief  Initialize using an existing planId
 *
 *   If using Swift and want enumerated results, please use the Swift extension method
 *
 *  @param apiKey            The APIKey assigned to you from Electric Imp
 *  @param planId            If setting the planId property, it must be an
 *    existing Id previously generated by Electric Imp
 *  @param completionHandler Block called when the configuration id is
 *    retrieved from the Electric Imp server. If error is nil, then the configId
 *    has been succesfully activated.
 *
 *  @return ConfigId that may or may not be active
 */
- (nonnull instancetype)initWithApiKey:(nonnull NSString *)apiKey planId:(nullable NSString *)planId completionHandler:(nullable BUConfigIdCompletionHandler)completionHandler NS_DESIGNATED_INITIALIZER;


#pragma mark - Properties

/*!
 *  @brief Retrieve the Api Key that is used when retrieving the configId
 */
@property (nonatomic, readonly, nullable) NSString *apiKey;

/*!
 *  @brief Retrieve the planId that is used for configuring the device
 *
 *   If setting the planId property, it must be an existing Id previously generated by Electric Imp
 *
 *   @see //FAQ.markdown For an explanation of what the planId is or code chunks, check @/link
 */
@property (nonatomic, readonly, nullable) NSString *planId;

/*!
 *  @brief  One time configuration token
 *
 *  The token is retrieved from the Electric Imp servers and identifies the
 *  short term configuration transaction between the server and the device.
 */
@property (nonatomic, readonly, nonnull) NSString *token;

/*!
 *  @brief  Indicates if the configId has been retrieved from the server
 *
 *  This property is true when the configId is ready to be used. If it is false
 *  the id has not been retrieved yet, or there was an error (be sure to check
 *  for error in the initialization methods completion handler).
 */
@property (nonatomic, readonly) BOOL isActive;

@end
