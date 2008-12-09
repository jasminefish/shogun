classifier_name = 'GPBTSVM';
classifier_epsilon = 1e-05;
init_random = 42;
classifier_label_type = 'twoclass';
classifier_tube_epsilon = 0.01;
classifier_accuracy = 0.0001;
kernel_data_train = {'TGGGCACTTCAACGATCTTTGGGGGTGTTAACGTCGGAGTAGGAATCAAGGGATCCCCTT', 'CTTTAGCTAGCCGTGTCGCAGGGGGAAGCACGCGGCTGGGAGCTTGCACCCGATATTGGC', 'GCCGCGCCAACAATAGCTCCGCGATCCGCTCGATGAACTCCACGTGTGACGTTAAATTTC', 'GCCGAATTCGCGTTGACCCTCACTAGCACGGTCATCGTCGACATAGTGGCCCGTTTTCGT', 'CTCGGTAGGCTGGCCGCATGGCCCCGGCACAATGGCTGTCTTTACCCTAACAATGACCAG', 'GGGATTTATTTAGTGGTCGCTAGGTGTTACACGTTAAGGCTTCTCGCATCGCAACGCGGG', 'CTCCACAGACTCAATACGGGTACCACCGGCGCCGAACTGATGGTCAGGGGTTTTTACCTG', 'GACGACCCGCGATCGGATGCATTACTGTCGCAGTCCGGTTATTTGTACTAATTATGGTCA', 'CGGTTGTAATAAGCTCACGCGTTCCGTTAGCAACCAGCGCACAGAGAGTACAGCGGTGGC', 'TTCTCTTAGCCCGAAGAAACCATGCCCGAATCCTGCGAGCTTTTGCCGTATTTTCAACGT', 'TGAAACGACAGCCCTAGGGTCCAGCAGGAGGACGGCCGTGACTATTATCTCCGTAGACCC'};
kernel_name = 'WeightedDegreePositionString';
classifier_type = 'kernel';
kernel_feature_class = 'string';
classifier_sv_sum = 55;
kernel_data_test = {'CAAACTATGGGTAGGGTAGGCCGTCTCAAACCGGAACGAATTACCTGAGCCCCCACATAA', 'GTTCAGGATATTGTGACACGCCGTACAGAGCATACACGCACGTGGACAAAGGTAGTGCCA', 'CGAAGTCGCACGTAGCGACTGCCCCTTCCTCGAGGTTAGTCAACCGATCACCACAGTCGG', 'ATTAAAAGCTGGGACGAATGCGTCATCACTACATAGTATTTAGTTATCACTCGTCGCCGT', 'GTAAGACGACGGTGCTTAAGGTGGTGATCTTGGCCCGTGACTCGTGCTATAATAGTTTCG', 'ACTCGGGTAGTCAGCATGTTGACATACGCAGAACGGCGCTAGTTACGATGGAGGTAACAG', 'TCTAAACTAGCTAAACCTGGGACTTTTAAACACGTGTAAGCCCCGCGGCCACGTGAGGCG', 'CGGAGAATTACACTTGCGCTTGCCATCCCTATTTCACCAGCTAGTTTGTCGAAAACAATA', 'GATTGGATTTGCTCGATAAGTGAATTTCTCGCCTGCCAGAAGGTGTTTGCTCACATGGGC', 'AGGCTAAACTTCGGAATGTCGACGCACAGCAAAGATAATGATCTGGTAGCAAAGGGACTC', 'GTTGTCTACATCAATTGGCCTACCCCGAGAAATCGGGCCCGCTTAAGCATATGTAAGACC', 'AATAAGTCAGTTGCGAGGTCAGGTACGCTCTGTCTCGACCCTATTAGCACTAGGTAGGGT', 'TACCCCCCTATCGTCCCCTTAACAGAGACGCTTCATTTATCGTATCTCTAGGCAGAGCTA', 'AACACTGGAGATCCCTAGAGTCCTGCGGATCATCAGTTTTACTCGGCTGCTCAGTTTGCT', 'TAATTTTGGGAGGGGCACAATACGGATTACTTGACGACGCTTCTATAAGCTCCGCCGTTT', 'CGCGCTGTTTTCCCAGGGTTACCCTGGTTAGCCACCCGTAATATGCAAAAGAGGCAAAGC', 'TCCGGCAGCCGCGGGGGGTCCTGATAGTTAGCCAGCAGGTTCTTCACCGGGGATCTATAA'};
classifier_classified = [-0.816062463, -0.832024144, -0.843646464, -0.820805519, -0.835961933, -0.82198082, -0.821511643, -0.824506853, -0.824010772, -0.819457623, -0.812054127, -0.830270182, -0.827553448, -0.827726147, -0.811060666, -0.809009132, -0.806585523];
kernel_alphabet = 'DNA';
classifier_C = 0.23;
kernel_feature_type = 'Char';
classifier_labels = [1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1];
classifier_num_threads = 1;
classifier_bias = -0.823754310463;
kernel_arg0_degree = 20;
classifier_alpha_sum = -3.88578058619e-16;
kernel_seqlen = 60;
classifier_linadd_enabled = 'True';