#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "nnet_utils/nnet_code_gen.h"
#include "nnet_utils/nnet_helpers.h"
// hls-fpga-machine-learning insert includes
//#include "nnet_utils/nnet_SRN_by_cycle.h"
//#include "nnet_utils/nnet_gaussian_sample_array_stream.h"
#include "nnet_utils/nnet_SRN_expand_states.h"

#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_activation_array_stream.h"
#include "nnet_utils/nnet_activation_stream.h"
#include "nnet_utils/nnet_bidirectional.h"
#include "nnet_utils/nnet_conv1d.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_array_stream.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"
#include "nnet_utils/nnet_explogvar_stream.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_merge_stream.h"
#include "nnet_utils/nnet_recurrent.h"
#include "nnet_utils/nnet_recurrent_array_stream.h"
#include "nnet_utils/nnet_sepconv1d_array_stream.h"
#include "nnet_utils/nnet_sepconv1d_stream.h"
#include "nnet_utils/nnet_stream.h"

// hls-fpga-machine-learning insert weights
#include "weights/fw2.h"
#include "weights/bw2.h"
#include "weights/fwr2.h"
#include "weights/bwr2.h"
#include "weights/fb2.h"
#include "weights/fbr2.h"
#include "weights/bb2.h"
#include "weights/bbr2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w19.h"
#include "weights/wr19.h"
#include "weights/b19.h"
#include "weights/br19.h"
#include "weights/w26.h"
#include "weights/b26.h"
#include "weights/w27.h"
#include "weights/b27.h"

// hls-fpga-machine-learning insert layer-config
// Encoder_BidirectionalGRU
struct config2_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_1;
    static const unsigned n_out = N_OUT_2 * 3 /2;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 13440;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense2_t accum_t;
    typedef forward_bias2_t bias_t;
    typedef forward_weight2_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config2_2 : nnet::dense_config {
    static const unsigned n_in = N_OUT_2/2;
    static const unsigned n_out = N_OUT_2 * 3 /2;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_OUT_2/2;
    static const unsigned n_zeros = 3;
    static const unsigned n_nonzeros = 12285;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense2_t accum_t;
    typedef forward_bias2_t bias_t;
    typedef forward_weight2_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct hard_sigmoid_config2_recr  : nnet::hard_activ_config {
    static const unsigned n_in = N_OUT_2 * 2 /2;
    static const slope2_t slope;
    static const shift2_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope2_t hard_sigmoid_config2_recr::slope = 0.5;
const shift2_t hard_sigmoid_config2_recr::shift = 0.5;

struct hard_tanh_config2 : nnet::hard_activ_config{
    static const unsigned n_in = N_OUT_2/2;
    static const slope2_t slope;
    static const shift2_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope2_t hard_tanh_config2::slope = 0.5;
const shift2_t hard_tanh_config2::shift = 0.5;

struct config2_f : nnet::gru_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef forward_weight2_t weight_t;  // Matrix
    typedef forward_bias2_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef hard_sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    typedef state2_t state_t;
    typedef act2_t act_t;
    typedef recr_act2_t recr_act_t;
    static const unsigned merge_mode = nnet::concat;
};

struct config2_b : nnet::gru_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef backward_weight2_t weight_t;  // Matrix
    typedef backward_bias2_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef hard_sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    typedef state2_t state_t;
    typedef act2_t act_t;
    typedef recr_act2_t recr_act_t;
    static const unsigned merge_mode = nnet::concat;
};

struct config2 : nnet::bidirectional_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef backward_weight2_t weight_t;  // Matrix
    typedef backward_bias2_t bias_t;  // Vector

    typedef config2_f config_rnn_layer_f;
    typedef config2_b config_rnn_layer_b;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = N_OUT_2;
    static const unsigned n_state = N_OUT_2/2;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const unsigned merge_mode = nnet::concat;
};

// q_act_postencoder
struct linear_config3 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned n_chan = N_OUT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act_postencoder_table_t table_t;
};

// dense_mean
struct config4 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 8192;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum4_t accum_t;
    typedef bias4_t bias_t;
    typedef weight4_t weight_t;
    typedef layer4_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// dense_logvar
struct config6 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 1;
    static const unsigned n_nonzeros = 8191;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum6_t accum_t;
    typedef bias6_t bias_t;
    typedef weight6_t weight_t;
    typedef layer6_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_activation_30
struct linear_config8 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_30_table_t table_t;
};

// q_activation_32
struct linear_config9 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_32_table_t table_t;
};


// exponent_logvar_5
struct config10 : nnet::explogvar_config {
    static const unsigned n_elem = 64;
    static const unsigned table_size = 1024;
    typedef exponent_logvar_5_exp_table_t exp_table_t;
};

// standard_random_normal_5
struct config11 : nnet::srn_config {
    static const unsigned n_elem = 64;
    static const unsigned seed = 42;
    static const unsigned n_samples = 4;
    typedef ap_fixed<32,16> seed_t;
};

//nnet::GRNGArray<config11::n_elem, config11::n_samples, typename config11::seed_t> normal{config11::seed};
ap_uint<32> state[config11::n_elem][config11::n_samples] = 
{
    {939911724, 3612297920, 3251192044, 35248278},
    {478083850, 1342673360, 1003776794, 2969361973},
    {3673694713, 3157212776, 1567718244, 3717380010},
    {2474015117, 872779235, 292193879, 1015849953},
    {1722776337, 3236169624, 3586344623, 4055164768},
    {3793860255, 3527199809, 2683416204, 3411341340},
    {1803763054, 2657512785, 2828609371, 929640809},
    {525640053, 1312896208, 2567980362, 4208117698},
    {1817503778, 770785436, 1331567968, 1383908681},
    {2043029939, 4058940250, 1142546993, 2281270249},
    {4252458370, 2041618751, 3273240969, 1922820525},
    {342897302, 1458774616, 4292434272, 1476576983},
    {394501186, 1164521446, 2004662916, 80296478},
    {3838100148, 3516141659, 3177483805, 478946113},
    {1039923647, 474162433, 1514126305, 753743310},
    {126580487, 3012457256, 665539376, 2213189040},
    {1809918644, 3226488526, 441032424, 1727499418},
    {3323629604, 1694077057, 1106164412, 4258072117},
    {598575624, 3175585295, 2523649412, 2046078132},
    {1999070106, 1704931826, 3731611536, 106268380},
    {2201104094, 4131479051, 116506628, 3360253488},
    {2574319533, 965170946, 4211419869, 2860863488},
    {440969821, 3613023158, 2857619048, 3055175411},
    {472077987, 2379232866, 2310798229, 3070466825},
    {3269404128, 2044487960, 652004537, 2063927112},
    {3623322058, 3156998441, 3766928272, 1489196456},
    {387792103, 3360785904, 71605387, 1274288304},
    {2413760307, 746311557, 343342544, 3397957956},
    {3301224841, 2144787661, 3720719436, 453164897},
    {579575221, 2148461980, 2106430724, 1713768247},
    {221117773, 2654697291, 186771672, 2167483138},
    {1518351942, 1816250467, 1095469283, 3769493399},
    {3243074142, 3641817447, 444343764, 1691835279},
    {940100572, 2312261143, 3370487405, 2186538294},
    {1573813392, 3715002296, 3466517099, 3150512088},
    {4210231790, 2408187507, 344549267, 4277008262},
    {3079012174, 3626655163, 1319988405, 294920560},
    {2031925293, 3800333707, 3181821021, 1564033360},
    {382917642, 3232196956, 3791721952, 2878062208},
    {3751037073, 19075322, 2238081849, 3216116632},
    {559519663, 1404999685, 3393645450, 2390448697},
    {4066065798, 3394401065, 3714800472, 384569339},
    {632322102, 874506130, 654953998, 2150227585},
    {3076409214, 150037156, 962092888, 1708688620},
    {1225481438, 1661449727, 581031163, 54766476},
    {226660301, 3220924730, 2000877552, 831504115},
    {1491728410, 540796655, 613146469, 365241290},
    {2557792068, 3303213117, 295768365, 3178019313},
    {886907787, 397820688, 2397218507, 1313915864},
    {2719641045, 982843889, 2691241949, 3823025250},
    {1757323945, 144775566, 985713343, 3953204910},
    {2083608861, 3176373527, 759720896, 4207845463},
    {2564658210, 4250209218, 2945251035, 2060032055},
    {3417173113, 2421372232, 2859980284, 4271734620},
    {2748808686, 4166111492, 1264612204, 152244674},
    {4038792073, 1552523238, 2434890566, 1440977166},
    {3593336065, 2781930380, 283755896, 977220409},
    {1558063356, 2019642280, 697874471, 2492960857},
    {3657290907, 3630659410, 4247295726, 2087704377},
    {3276096395, 3671768455, 153767195, 3922823891},
    {2348653055, 1810604402, 2638148969, 1102564215},
    {2931459322, 2326823202, 676466155, 51711863},
    {738911072, 3572154967, 2910483232, 2289608648},
    {3277347166, 3951786031, 4032081168, 2194188789},
};


// q_activation_33
struct linear_config12 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_33_table_t table_t;
};

// q_activation_31
struct linear_config13 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_31_table_t table_t;
};

// multiply_5
struct config14 : nnet::merge_config {
    static const unsigned n_elem = N_LAYER_6;
};

// q_activation_34
struct linear_config15 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_34_table_t table_t;
};

// add_5
struct config16 : nnet::merge_config {
    static const unsigned n_elem = N_LAYER_4;
};

// q_activation_35
struct linear_config18 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_35_table_t table_t;
};

// DecoderGRU
struct config19_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_17;
    static const unsigned n_out = N_OUT_19 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_17;
    static const unsigned n_zeros = 2;
    static const unsigned n_nonzeros = 12286;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense19_t accum_t;
    typedef bias19_t bias_t;
    typedef weight19_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config19_2 : nnet::dense_config {
    static const unsigned n_in = N_OUT_19;
    static const unsigned n_out = N_OUT_19 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_OUT_19;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 12288;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense19_t accum_t;
    typedef bias19_t bias_t;
    typedef weight19_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct hard_sigmoid_config19_recr  : nnet::hard_activ_config {
    static const unsigned n_in = N_OUT_19 * 2;
    static const slope19_t slope;
    static const shift19_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope19_t hard_sigmoid_config19_recr::slope = 0.5;
const shift19_t hard_sigmoid_config19_recr::shift = 0.5;

struct hard_tanh_config19 : nnet::hard_activ_config{
    static const unsigned n_in = N_OUT_19;
    static const slope19_t slope;
    static const shift19_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope19_t hard_tanh_config19::slope = 0.5;
const shift19_t hard_tanh_config19::shift = 0.5;

struct config19 : nnet::gru_config {
    typedef accum_dense19_t accum_dense_t;
    typedef accum19_t accum_t;
    typedef weight19_t weight_t;  // Matrix
    typedef bias19_t bias_t;  // Vector
    typedef config19_1 mult_config1;
    typedef config19_2 mult_config2;
    typedef hard_sigmoid_config19_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config19 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_17;
    static const unsigned n_out = N_OUT_19;
    static const unsigned n_state = N_OUT_19;
    static const unsigned n_sequence = N_INPUT_1_17;
    static const unsigned n_sequence_out = N_TIME_STEPS_19;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    static const bool use_initial = 1;
    typedef state19_t state_t;
    typedef act19_t act_t;
    typedef recr_act19_t recr_act_t;
};

// q_act_postdecoder
struct linear_config20 : nnet::activ_config {
    static const unsigned n_in = 4672;
    static const unsigned n_chan = N_OUT_19;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act_postdecoder_table_t table_t;
};

// dense_factor
struct config26_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 4;
    static const unsigned reuse_factor = 64;
    static const unsigned strategy = nnet::resource;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef dense_factor_bias_t bias_t;
    typedef dense_factor_weight_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config26 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_width = 73;
    static const unsigned n_chan = 64;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_width;
    static const unsigned n_filt = 4;
    static const unsigned stride_width = 1;
    static const unsigned dilation = 1;
    static const unsigned out_width = 73;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_width = 73;
    static const ap_uint<filt_width> pixels[min_width];
    static const unsigned n_partitions = 73;
    static const unsigned n_pixels = out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv1DBuffer<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef dense_factor_bias_t bias_t;
    typedef dense_factor_weight_t weight_t;
    typedef config26_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index = nnet::scale_index_unscaled<K, S, W>;
};
const ap_uint<config26::filt_width> config26::pixels[] = {0};

// q_act3_postfactor
struct linear_config23 : nnet::activ_config {
    static const unsigned n_in = 292;
    static const unsigned n_chan = N_FILT_26;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act3_postfactor_table_t table_t;
};

// nerual_dense
struct config27_mult : nnet::dense_config {
    static const unsigned n_in = 4;
    static const unsigned n_out = 70;
    static const unsigned reuse_factor = 4;
    static const unsigned strategy = nnet::resource;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef nerual_dense_bias_t bias_t;
    typedef nerual_dense_weight_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config27 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_width = 73;
    static const unsigned n_chan = 4;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_width;
    static const unsigned n_filt = 70;
    static const unsigned stride_width = 1;
    static const unsigned dilation = 1;
    static const unsigned out_width = 73;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_width = 73;
    static const ap_uint<filt_width> pixels[min_width];
    static const unsigned n_partitions = 73;
    static const unsigned n_pixels = out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv1DBuffer<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef nerual_dense_bias_t bias_t;
    typedef nerual_dense_weight_t weight_t;
    typedef config27_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index = nnet::scale_index_unscaled<K, S, W>;
};
const ap_uint<config27::filt_width> config27::pixels[] = {0};


#endif
