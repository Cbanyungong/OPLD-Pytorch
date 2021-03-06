#include "nms.h"
#include "ml_nms.h"
#include "ROIAlign.h"
#include "ROIPool.h"
#include "SigmoidFocalLoss.h"
#include "deform_conv.h"
#include "deform_pool.h"
#include "PoolPointsInterp.h"

#include "ROIAlignRotated.h"
#include "box_iou_rotated.h"
#include "nms_rotated.h"
#include "box_iou_polygon.h"
#include "nms_polygon.h"

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("nms", &nms, "non-maximum suppression");
  m.def("ml_nms", &ml_nms, "multi-label non-maximum suppression");
  m.def("roi_align_forward", &ROIAlign_forward, "ROIAlign_forward");
  m.def("roi_align_backward", &ROIAlign_backward, "ROIAlign_backward");
  m.def("roi_pool_forward", &ROIPool_forward, "ROIPool_forward");
  m.def("roi_pool_backward", &ROIPool_backward, "ROIPool_backward");
  m.def("sigmoid_focalloss_forward", &SigmoidFocalLoss_forward, "SigmoidFocalLoss_forward");
  m.def("sigmoid_focalloss_backward", &SigmoidFocalLoss_backward, "SigmoidFocalLoss_backward");
  m.def("pool_points_interp_forward", &PoolPointsInterp_forward, "PoolPointsInterp_forward");
  m.def("pool_points_interp_backward", &PoolPointsInterp_backward, "PoolPointsInterp_backward");
  // dcn-v2
  m.def("deform_conv_forward", &deform_conv_forward, "deform_conv_forward");
  m.def("deform_conv_backward_input", &deform_conv_backward_input, "deform_conv_backward_input");
  m.def("deform_conv_backward_parameters", &deform_conv_backward_parameters, "deform_conv_backward_parameters");
  m.def("modulated_deform_conv_forward", &modulated_deform_conv_forward, "modulated_deform_conv_forward");
  m.def("modulated_deform_conv_backward", &modulated_deform_conv_backward, "modulated_deform_conv_backward");
  m.def("deform_psroi_pooling_forward", &deform_psroi_pooling_forward, "deform_psroi_pooling_forward");
  m.def("deform_psroi_pooling_backward", &deform_psroi_pooling_backward, "deform_psroi_pooling_backward");
  // rotated
  m.def("box_iou_rotated", &box_iou_rotated, "IoU for rotated boxes");
  m.def("nms_rotated", &nms_rotated, "NMS for rotated boxes");
  m.def("roi_align_rotated_forward", &ROIAlignRotated_forward, "Forward pass for Rotated ROI-Align Operator");
  m.def("roi_align_rotated_backward", &ROIAlignRotated_backward, "Backward pass for Rotated ROI-Align Operator");
  // polygon
  m.def("box_iou_polygon", &box_iou_polygon, "IoU for polygon");
  m.def("nms_polygon", &nms_polygon, "NMS for polygon");
}
