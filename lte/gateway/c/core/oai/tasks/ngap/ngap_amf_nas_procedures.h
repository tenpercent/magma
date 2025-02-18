/**
 * Copyright 2020 The Magma Authors.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "lte/gateway/c/core/oai/common/common_defs.h"
#include "lte/gateway/c/core/oai/lib/3gpp/3gpp_38.401.h"
#include "lte/gateway/c/core/oai/lib/bstr/bstrlib.h"
#include "lte/gateway/c/core/oai/common/common_types.h"
#include "lte/gateway/c/core/oai/include/amf_app_messages_types.h"
#include "lte/gateway/c/core/oai/include/ngap_messages_types.h"
#include "lte/gateway/c/core/oai/tasks/ngap/ngap_state.h"
struct ngap_message_s;

#define FETCH_AMF_SET_ID_FROM_PDU(aSN, Amf_Set_Id)           \
  DevCheck((aSN).size == 2, (aSN).size, 0, 0);               \
  DevCheck((aSN).bits_unused == 6, (aSN).bits_unused, 6, 0); \
  Amf_Set_Id = (aSN.buf[0] << 2) + ((aSN.buf[1] >> 6) & 0x03);

/** \brief Handle an Initial UE message.
 * \param assocId lower layer assoc id (SCTP)
 * \param stream SCTP stream on which data had been received
 * \param message The message as decoded by the ASN.1 codec
 * @returns -1 on failure, 0 otherwise
 **/
status_code_e ngap_amf_handle_initial_ue_message(ngap_state_t* state,
                                                 const sctp_assoc_id_t assocId,
                                                 const sctp_stream_id_t stream,
                                                 Ngap_NGAP_PDU_t* message);

/** \brief Handle an Uplink NAS transport message.
 * Process the RRC transparent container and forward it to NAS entity.
 * \param assocId lower layer assoc id (SCTP)
 * \param stream SCTP stream on which data had been received
 * \param message The message as decoded by the ASN.1 codec
 * @returns -1 on failure, 0 otherwise
 **/
status_code_e ngap_amf_handle_uplink_nas_transport(
    ngap_state_t* state, const sctp_assoc_id_t assocId,
    const sctp_stream_id_t stream, Ngap_NGAP_PDU_t* message);

/** \brief Handle an Downlink NAS transport message.
 * \param state ngap state
 * \param gnb_ue_ngap_id  gnb_ue_ngap_id
 * \param ue_id amf_ue_ngap_id
 * \param payload message to transmit
 * \param imsi64 IMSI value
 * @returns int
 **/
status_code_e ngap_generate_downlink_nas_transport(
    ngap_state_t* state, const gnb_ue_ngap_id_t gnb_ue_ngap_id,
    const amf_ue_ngap_id_t ue_id, STOLEN_REF bstring* payload, imsi64_t imsi64);

/** \brief Handle a NAS non delivery indication message from gNB
 * \param assocId lower layer assoc id (SCTP)
 * \param stream SCTP stream on which data had been received
 * \param message The message as decoded by the ASN.1 codec
 * @returns -1 on failure, 0 otherwise
 **/
status_code_e ngap_amf_handle_nas_non_delivery(ngap_state_t* state,
                                               const sctp_assoc_id_t assocId,
                                               const sctp_stream_id_t stream,
                                               Ngap_NGAP_PDU_t* message);

void ngap_handle_conn_est_cnf(
    ngap_state_t* state,
    Ngap_initial_context_setup_request_t* const conn_est_cnf_p);

/** \brief communicates amf_ue_id to Ngap.
 * \param state ngap state
 * \param notification_p common structure for sharing msg
 * @returns nothing
 **/
void ngap_handle_amf_ue_id_notification(
    ngap_state_t* state,
    const itti_amf_app_ngap_amf_ue_id_notification_t* const notification_p);

/** \brief Handle a NAS non delivery indication message from gNB
 * \param assocId lower layer assoc id (SCTP)
 * \param stream SCTP stream on which data had been received
 * \param message The message as decoded by the ASN.1 codec
 * @returns -1 on failure, 0 otherwise
 **/
status_code_e ngap_amf_handle_nas_non_delivery(ngap_state_t* state,
                                               const sctp_assoc_id_t assocId,
                                               const sctp_stream_id_t stream,
                                               Ngap_NGAP_PDU_t* message);

status_code_e ngap_amf_nas_pdusession_resource_setup_stream(
    itti_ngap_pdusession_resource_setup_req_t* const
        pdusession_resource_setup_req,
    m5g_ue_description_t* ue_ref, bstring* stream);

status_code_e ngap_generate_ngap_pdusession_resource_setup_req(
    ngap_state_t* state, itti_ngap_pdusession_resource_setup_req_t* const
                             pdusession_resource_setup_req);

status_code_e ngap_generate_ngap_pdusession_resource_rel_cmd(
    ngap_state_t* state,
    itti_ngap_pdusessionresource_rel_req_t* const pdusessionresource_rel_cmd);
