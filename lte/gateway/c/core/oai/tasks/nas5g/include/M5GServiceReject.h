/*
   Copyright 2020 The Magma Authors.
   This source code is licensed under the BSD-style license found in the
   LICENSE file in the root directory of this source tree.
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#pragma once
#include <sstream>
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GExtendedProtocolDiscriminator.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GSecurityHeaderType.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GSpareHalfOctet.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GMessageType.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GMMCause.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GPDUSessionStatus.h"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GGprsTimer2.h"

namespace magma5g {
// ServiceAccept Message Class
class ServiceRejectMsg {
 public:
#define M5G_SERVICE_REJECT_MINIMUM_LENGTH 3
  ExtendedProtocolDiscriminatorMsg extended_protocol_discriminator;
  SecurityHeaderTypeMsg sec_header_type;
  SpareHalfOctetMsg spare_half_octet;
  MessageTypeMsg message_type;
  M5GMMCauseMsg cause;
  M5GPDUSessionStatus pdu_session_status;
  GPRSTimer2Msg t3346Value;

  ServiceRejectMsg();
  ~ServiceRejectMsg();
  int DecodeServiceRejectMsg(ServiceRejectMsg* service_reject, uint8_t* buffer,
                             uint32_t len);
  int EncodeServiceRejectMsg(ServiceRejectMsg* service_reject, uint8_t* buffer,
                             uint32_t len);
};
}  // namespace magma5g
