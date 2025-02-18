"""
Copyright 2021 The Magma Authors.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import logging
from typing import Type

from magma.protocol_controller.config import Config


def configure_logger(config: Type[Config]):
    """
    Configure protocol controller logger

    Parameters:
        config: Protocol controller configuration object
    """

    logging.basicConfig(level=config.LOG_LEVEL)
