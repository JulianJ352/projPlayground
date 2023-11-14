'''
Code by Julian Johnson
For LSU Senior Design 2023 P18
11/13/2023

code largely pulled from depthai, sklearn, & other assoicated modules
Also see:
https://forum.derivative.ca/t/camera-oak-d-how-import-new-python-examples/368737/3
https://github.com/mavlink/MAVSDK-Python#mavsdk-python
'''
import matplotlib
import numpy as np
import tensorflow as tf
import keras
from depthai_sdk import OakCamera
from depthai_sdk.trigger_action.actions.record_action import RecordAction
from depthai_sdk.trigger_action.triggers.detection_trigger import DetectionTrigger
from depthai_sdk.visualize.configs import BboxStyle, TextPosition
from mavsdk import system

import sklearn as sk


def print_num_objects(packet):
    print(f'Number of objects detected: {len(packet.detections)}')

with OakCamera(recording = 'c:/Desktop/Oakoutput.VIDEO') as oak:
    color = oak.create_camera('color', resolution = '1080p')
    stereo = oak.create_stereo(resolution='800p')
    yoloCurr=oak.create_nn('yolov6n_coco_640x640', input=color)
    pipeline = dai.Pipeline()
    camRgb = pipeline.create(dai.node.ColorCamera)
    xoutRgb = pipeline.create(dai.node.XLinkOut
    #yoloCurr = oak.create_nn('yolo-v3-tiny-tf', input = color)
    #need to normalize for yolov4t?
    #yoloCurr = oak.create_nn('yolov4_tiny_coco_416x416', input = color)
    #yoloCurr = oak.create_nn('yolov7tiny_coco_640x352', input = color)
    #yoloCurr = oak.create_nn('yolov7tiny_coco_416x416', input = color)
    #yoloCurr = oak.create_nn('yolov8n_coco_640x352', input = color )
    oak.record([color,yolo], path='./records', record_type=RecordType.VIDEO)
    trigger = 1
    action = 1
    oak.trigger_action(trigger=trigger, action=action)

     visualizer = oak.visualize(det.out.main, record_path='./test.mp4')
    # Chained methods for setting visualizer parameters
    visualizer.detections(  # Detection-related parameters
        color=(0, 255, 0),
        thickness=2,
        bbox_style=BboxStyle.RECTANGLE,  # Options: RECTANGLE, CORNERS, ROUNDED_RECTANGLE, ROUNDED_CORNERS
        label_position=TextPosition.MID,
    ).text(  # Text-related parameters
        font_color=(255, 255, 0),
        auto_scale=True
    ).output(  # General output parameters
        show_fps=True,
    ).tracking(  # Tracking-related parameters
        line_thickness=5
    )
    oak.start(blocking=True)


#analyzing information from nerual network:
#sklearn metrics will be source of analysis, output to text file

MAE = sk.metrics.mean_absolute_error(y_true, y_pred, *, sample_weight=None, multioutput='uniform_average')
APS = sk.metrics.average_precision_score(y_true, y_score, *, average='macro', pos_label=1, sample_weight=None)

#plotting
cMatrix = sk.metrics.ConfusionMatrixDisplay(confusion_matrix, *, display_labels=None)
PRDisp = sk.metrics.PrecisionRecallDisplay(precision, recall, *, average_precision=None, estimator_name=None, pos_label=None, prevalence_pos_label=None)
calibDis = sk.calibration.CalibrationDisplay(prob_true, prob_pred, y_prob, *, estimator_name=None, pos_label=None)
covError = sk.metrics.coverage_error(y_true, y_score, *, sample_weight=None)
labRMPS = sk.metrics.label_ranking_average_precision_score(y_true, y_score, *, sample_weight=None)
labRLoss = sk.metrics.label_ranking_loss(y_true, y_score, *, sample_weight=None

outputFile = open("OakAnalysis.txxt", "a")
File_object.write(MAE)
File_object.write(APS)
File_object.write(cMatrix)
File_object.write(PRDisp)
File_object.write(calibDis)

outputFile.close()
