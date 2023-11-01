from depthai_sdk import OakCamera

with OakCamera() as oak:
    color = oak.create_camera('color', resolution='1080p', fps=20, encode='h264')
    stereo = oak.create_stereo('400p', encode='h264')
    yolo = oak.create_nn('yolov6nr3_coco_640x352', input=color)

    oak.visualize([color.out.encoded, stereo.out.encoded, yolo.out.encoded])
    oak.start(blocking=True)
