/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2022 The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "fluent-bit/flb_output.h"
#include <fluent-bit/flb_log_event_decoder.h>
#include <fluent-bit/flb_output_plugin.h>
#include <fluent-bit/flb_pack.h>
#include <fluent-bit/flb_time.h>
#include <fluent-bit/flb_utils.h>

#ifdef __cplusplus
}
#endif

#include "pulsar_config.h"

int pulsar_cb_init(struct flb_output_instance *ins, struct flb_config *config,
                   void *data) {
  struct flb_out_pulsar *ctx;
  ctx = flb_out_pulsar_create(ins, config);
  if (!ctx) {
    flb_plg_error(ins, "failed to initialize");
    return -1;
  }
  
  return 0;
}

int pulsar_cb_pre_run(void *data, struct flb_config *config) { return 0; }

int pulsar_cb_exit(void *data, struct flb_config *config) { return 0; }

static struct flb_config_map config_map[] = {

};

struct flb_output_plugin out_pulsar_native_plugin = {
    .name = "pulsar",
    .description = "pulsar output plugin",
    .cb_init = pulsar_cb_init,
    .cb_pre_run = pulsar_cb_pre_run,
    .cb_exit = pulsar_cb_exit,
    .flags = 0,
    .config_map = config_map,
};
