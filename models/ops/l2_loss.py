import torch


def l2_loss(input, target):
    pos_inds = torch.nonzero(target > 0.0).squeeze(1)
    if pos_inds.shape[0] > 0:
        cond = torch.abs(input[pos_inds] - target[pos_inds])
        loss = 0.5 * cond ** 2 / pos_inds.shape[0]
    else:
        loss = input * 0.0
    return loss.sum()
