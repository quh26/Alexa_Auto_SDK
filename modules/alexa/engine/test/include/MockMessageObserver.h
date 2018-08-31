/*
 * Copyright 2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef AACE_TEST_UNIT_MOCK_MESSAGEOBSERVER_H_
#define AACE_TEST_UNIT_MOCK_MESSAGEOBSERVER_H_

#include <AVSCommon/SDKInterfaces/AudioPlayerInterface.h>

namespace aace {    
namespace test {
namespace unit {

using namespace alexaClientSDK;
using namespace alexaClientSDK::avsCommon;

// This class allows us to test MessageObserver interaction
class MockMessageObserver : public alexaClientSDK::avsCommon::sdkInterfaces::MessageObserverInterface {
public:
    MOCK_METHOD2(receive, void(const std::string& contextId, const std::string& message));
};

}
}
}
#endif //AACE_TEST_UNIT_MOCK_MESSAGEOBSERVER_H_