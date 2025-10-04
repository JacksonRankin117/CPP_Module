"""
This isn't C++, I know, but this was the best way to visualize the data I could find. Julia also handles animations 
better than Pythin does
"""

using CSV, DataFrames, GLMakie
using GeometryBasics: Point3f

# Load data
df = CSV.read("11_GravSim/output.csv", DataFrame)

N = 50
nframes = nrow(df)

# Parse positions into array of matrices: frames × (N × 3)
positions = Vector{Matrix{Float32}}(undef, nframes)
for i in 1:nframes
    row = df[i, :]
    pos_frame = zeros(Float32, N, 3)
    for p in 0:N-1
        pos_frame[p+1, 1] = row[2 + p*3]
        pos_frame[p+1, 2] = row[3 + p*3]
        pos_frame[p+1, 3] = row[4 + p*3]
    end
    positions[i] = pos_frame
end

# Compute axis limits from all positions
all_pos = reduce(vcat, positions)
xmin, xmax = minimum(all_pos[:, 1]), maximum(all_pos[:, 1])
ymin, ymax = minimum(all_pos[:, 2]), maximum(all_pos[:, 2])
zmin, zmax = minimum(all_pos[:, 3]), maximum(all_pos[:, 3])

# Create Figure and Axis3 (3D axis)
fig = Figure(size = (800, 600))
lim = 10000
ax = Axis3(fig[1, 1], limits = ((-lim, lim), (-lim, lim), (-lim, lim)))

# Initial scatter plot of first frame
scatter_obj = scatter!(
    ax,
    [Point3f(pos[1], pos[2], pos[3]) for pos in eachrow(positions[1])],
    markersize = 8,
    color = :purple
)

fps = 100

# Record animation to MP4
record(fig, "animation-50.mp4", 1:nframes; framerate = fps) do i
    scatter_obj[1][] = [Point3f(pos[1], pos[2], pos[3]) for pos in eachrow(positions[i])]
end
