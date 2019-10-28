#!/bin/bash
#
#  refreshframeworks.sh
#  Assistant
#
#  Copyright © 2018. SAP SE or an SAP affiliate company. All rights reserved.
#
#  No part of this publication may be reproduced or transmitted in any form or for any purpose
#  without the express permission of SAP SE.  The information contained herein may be changed
#  without prior notice.
#

# Usage:
#
# sh refreshframeworks.sh [PROJECT]
#
#   PROJECT: (optional) Directory where the project is available. Default: this project, so ./
#
#   ASSISTANT_LOCATION: Environment variable containing the path where Assistant is installed. The script checks for ASSISTANT_LOCATION environment location, if it is not set uses this default value: $DEFAULT_ASSISTANT_LOCATION

FRAMEWORK_NAMES=( SAPCommon SAPFiori SAPFioriFlows SAPFoundation SAPOData SAPOfflineOData )
DEFAULT_ASSISTANT_LOCATION="/Applications/SAP Cloud Platform SDK for iOS Assistant.app/Contents/Resources/iOSFrameworks/Release-fat/"

PROJECT="$1"

#
# No user serviceable parts below!
#

if [ -z "$PROJECT" ]; then
    export PROJECT="./"
fi

ASSISTANT_LOCATION="`launchctl getenv ASSISTANT_LOCATION`"

if [ -z "$ASSISTANT_LOCATION" ]; then
    export ASSISTANT_LOCATION="$DEFAULT_ASSISTANT_LOCATION"
fi

for i in ${FRAMEWORK_NAMES[@]}; do
    if [ ! -d "$PROJECT$i.framework" -a -d "$ASSISTANT_LOCATION$i.framework" ]; then
        cp -R "$ASSISTANT_LOCATION$i.framework" "$PROJECT"
    fi
done
