/*
 * Copyright (c) 2026 Pavithra C.P., BeagleBoard.org
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <greybus/greybus.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(gb_audio, CONFIG_GREYBUS_LOG_LEVEL);

static int gb_audio_init(struct gb_connection *connection)
{
    LOG_INF("Greybus Audio Control Plane initialized");
    return 0;
}

static void gb_audio_exit(struct gb_connection *connection)
{
    LOG_INF("Greybus Audio Control Plane exited");
}

/*Empty dispatch table for now (skeleton)*/
static struct gb_operation_handler gb_audio_handlers[] = {};

static struct gb_driver gb_audio_driver = {
    .init = gb_audio_init,
    .exit = gb_audio_exit,
    .handlers = gb_audio_handlers,
    .handler_count = ARRAY_SIZE(gb_audio_handlers),
};

GB_DRIVER_INIT(GREYBUS_PROTOCOL_AUDIO, &gb_audio_driver);
