#
# pool2d paddle model generator
#
import numpy as np
from save_model import saveModel
import sys


def pdpd_dropout(name : str, x, p, pdpd_attrs):
    import paddle as pdpd
    pdpd.enable_static()
    
    with pdpd.static.program_guard(pdpd.static.Program(), pdpd.static.Program()):
        node_x = pdpd.static.data(name='x', shape=x.shape, dtype='float32')
        out = pdpd.nn.functional.dropout(x=node_x, p=p, training=pdpd_attrs['training'], mode=pdpd_attrs['mode'])

        cpu = pdpd.static.cpu_places(1)
        exe = pdpd.static.Executor(cpu[0])
        # startup program will call initializer to initialize the parameters.
        exe.run(pdpd.static.default_startup_program())

        outs = exe.run(
            feed={'x': x},
            fetch_list=[out])             

        saveModel(name, exe, feedkeys=['x'], fetchlist=[out], inputs=[x],
                  outputs=[outs[0]], target_dir=sys.argv[1])

    return outs[0]


def main():
    p=0.5
    data = np.random.random(size=(3, 10, 3, 7)).astype('float32')
    pdpd_attrs = {
    'training' : False,
    'mode' : "downscale_in_infer"
    }
    pdpd_attrs2 = {
        'training' : False,
        'mode' : "upscale_in_train"
    }
    pdpd_dropout("dropout", data, p, pdpd_attrs)
    pdpd_dropout("dropout_upscale_in_train", data, p, pdpd_attrs2)

if __name__ == "__main__":
    main()     