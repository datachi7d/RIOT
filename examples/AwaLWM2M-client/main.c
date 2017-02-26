/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>

#include "awa/static.h"

int main(void)
{
    AwaFactoryBootstrapInfo bootstrapinfo;
    AwaStaticClient * awaClient = AwaStaticClient_New();

    AwaStaticClient_SetLogLevel(AwaLogLevel_Debug);
    AwaStaticClient_SetEndPointName(awaClient, "AwaStaticClient1");
    AwaStaticClient_SetCoAPListenAddressPort(awaClient, "::", 6000);
    AwaStaticClient_SetBootstrapServerURI(awaClient, "");

    AwaStaticClient_Init(awaClient);

    sprintf(bootstrapinfo.SecurityInfo.ServerURI, "%s", "coap://[::1]:5683");
    bootstrapinfo.SecurityInfo.SecurityMode = AwaSecurityMode_NoSec;
    sprintf(bootstrapinfo.SecurityInfo.PublicKeyOrIdentity, "[PublicKey]");
    sprintf(bootstrapinfo.SecurityInfo.SecretKey, "[SecretKey]");

    bootstrapinfo.ServerInfo.Lifetime = 60;
    bootstrapinfo.ServerInfo.DefaultMinPeriod = 1;
    bootstrapinfo.ServerInfo.DefaultMaxPeriod = -1;
    bootstrapinfo.ServerInfo.DisableTimeout = 86400;
    bootstrapinfo.ServerInfo.Notification = false;
    sprintf(bootstrapinfo.ServerInfo.Binding, "U");

    AwaStaticClient_SetFactoryBootstrapInformation(awaClient, &bootstrapinfo);

    while (1)
    {
        AwaStaticClient_Process(awaClient);
    }

    AwaStaticClient_Free(&awaClient);

    return 0;
}
