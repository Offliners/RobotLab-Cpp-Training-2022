q5_cfg = {
    # num of testcase
    'N' : 50,

    # Random seed
    'seed' : 0,

    # Boundart of tree depth
    'depth_lower' : 8,
    'depth_upper' : 32,

    # Probability of using parentheses
    'parentheses_prob' : 0.2,

    # Probability of using mod
    'mod_prob' : 0.4,

    # Probability of continue calculation
    'continue_cal_prob' : 0.97,
    'prob_decay' : 0.97,

    # Boundary of occured number
    'num_lower' : 1,
    'num_upper' : 20,

    # Boundary of result
    'result_min' : -9223372036854775808,
    'result_max' : 9223372036854775807,


    # testcase output path
    'save_path' : './testcase'
}