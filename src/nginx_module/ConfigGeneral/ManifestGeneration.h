#ifndef _PASSENGER_NGINX_MODULE_CONFIG_GENERAL_MANIFEST_GENERATION_H_
#define _PASSENGER_NGINX_MODULE_CONFIG_GENERAL_MANIFEST_GENERATION_H_

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include "cxx_supportlib/JsonTools/CBindings.h"

struct passenger_main_conf_s;
struct passenger_loc_conf_s;
typedef struct passenger_main_conf_s passenger_main_conf_t;
typedef struct passenger_loc_conf_s passenger_loc_conf_t;

typedef struct {
    ngx_conf_t *cf;

    PsgJsonValue *manifest;
    PsgJsonValue *global_config_container;
    PsgJsonValue *default_app_config_container;
    PsgJsonValue *default_loc_config_container;
    PsgJsonValue *app_configs_container;

    PsgJsonValue *empty_object, *empty_array;

    PsgJsonValueIterator *it, *end;
    PsgJsonValueIterator *it2, *end2;
    PsgJsonValueIterator *it3, *end3;
    PsgJsonValueIterator *it4, *end4;
} manifest_gen_ctx_t;

static PsgJsonValue *generate_config_manifest(ngx_conf_t *cf, passenger_loc_conf_t *toplevel_plcf);

static void init_config_manifest_generation(ngx_conf_t *cf, manifest_gen_ctx_t *ctx);
static void deinit_config_manifest_generation(manifest_gen_ctx_t *ctx);

static void recursively_generate_config_manifest_for_loc_conf(manifest_gen_ctx_t *ctx,
	passenger_loc_conf_t *plcf);
static int infer_loc_conf_app_group_name(manifest_gen_ctx_t *ctx,
	passenger_loc_conf_t *plcf, ngx_http_core_loc_conf_t *clcf, ngx_str_t *result);
static void generate_config_manifest_for_loc_conf(manifest_gen_ctx_t *ctx,
	passenger_loc_conf_t *plcf, ngx_http_core_srv_conf_t *cscf,
	ngx_http_core_loc_conf_t *clcf);
static void find_or_create_manifest_app_and_loc_options_containers(manifest_gen_ctx_t *ctx,
    passenger_loc_conf_t *plcf, ngx_http_core_srv_conf_t *cscf,
    ngx_http_core_loc_conf_t *clcf, PsgJsonValue **app_options_container,
    PsgJsonValue **loc_options_container);
static PsgJsonValue *find_manifest_loc_config_container(manifest_gen_ctx_t *ctx,
    PsgJsonValue *loc_configs_container, ngx_http_core_srv_conf_t *cscf,
    ngx_http_core_loc_conf_t *clcf);
static PsgJsonValue *create_manifest_loc_config_container(manifest_gen_ctx_t *ctx,
    PsgJsonValue *loc_configs_container, ngx_http_core_srv_conf_t *cscf,
    ngx_http_core_loc_conf_t *clcf);
static void init_manifest_option_container(manifest_gen_ctx_t *ctx, PsgJsonValue *doc);
static PsgJsonValue *find_or_create_manifest_option_container(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name,
    size_t option_name_len);
static PsgJsonValue *add_manifest_option_container_hierarchy_member(
    PsgJsonValue *option_container, ngx_str_t *source_file, ngx_uint_t source_line);

static void generate_config_manifest_for_autogenerated_main_conf(manifest_gen_ctx_t *ctx,
    passenger_main_conf_t *conf);
static void generate_config_manifest_for_autogenerated_loc_conf(manifest_gen_ctx_t *ctx,
    passenger_loc_conf_t *plcf, ngx_http_core_srv_conf_t *cscf,
    ngx_http_core_loc_conf_t *clcf);

static void reverse_manifest_value_hierarchies(manifest_gen_ctx_t *ctx);
static void reverse_value_hierarchies_in_options_container(PsgJsonValue *options_container,
    PsgJsonValueIterator *it, PsgJsonValueIterator *end);

static void add_manifest_options_container_dynamic_default(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name, size_t option_name_len,
    const char *desc, size_t desc_len);
static void add_manifest_options_container_static_default_str(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name, size_t option_name_len,
    const char *value, size_t value_len);
static void add_manifest_options_container_static_default_int(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name, size_t option_name_len,
    int value);
static void add_manifest_options_container_static_default_uint(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name, size_t option_name_len,
    unsigned int value);
static void add_manifest_options_container_static_default_bool(manifest_gen_ctx_t *ctx,
    PsgJsonValue *options_container, const char *option_name, size_t option_name_len,
    int value);

static void manifest_inherit_application_value_hierarchies(manifest_gen_ctx_t *ctx);
static void manifest_inherit_location_value_hierarchies(manifest_gen_ctx_t *ctx);
static void maybe_inherit_string_array_hierarchy_values(PsgJsonValue *value_hierarchy_doc,
    PsgJsonValueIterator *it, PsgJsonValueIterator *end);
static void maybe_inherit_string_keyval_hierarchy_values(PsgJsonValue *value_hierarchy_doc,
    PsgJsonValueIterator *it, PsgJsonValueIterator *end);

static void psg_json_value_append_vals(PsgJsonValue *doc, PsgJsonValue *doc2,
    PsgJsonValueIterator *it, PsgJsonValueIterator *end);
static int json_array_contains(PsgJsonValue *doc, PsgJsonValue *elem);

#endif /* _PASSENGER_NGINX_MODULE_CONFIG_GENERAL_MANIFEST_GENERATION_H_ */
